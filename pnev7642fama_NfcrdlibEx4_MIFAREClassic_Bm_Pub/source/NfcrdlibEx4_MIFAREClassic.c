/*----------------------------------------------------------------------------*/
/* Copyright 2012-2021,2023 NXP                                               */
/*                                                                            */
/* NXP Confidential. This software is owned or controlled by NXP and may only */
/* be used strictly in accordance with the applicable license terms.          */
/* By expressly accepting such terms or by downloading, installing,           */
/* activating and/or otherwise using the software, you are agreeing that you  */
/* have read, and that you agree to comply with and are bound by, such        */
/* license terms. If you do not agree to be bound by the applicable license   */
/* terms, then you may not retain, install, activate or otherwise use the     */
/* software.                                                                  */
/*----------------------------------------------------------------------------*/

/** \file
 * Example Source for NfcrdlibEx4_MIFAREClassic that uses the MIFARE Classic contactless IC implementation.
 * This example will load/configure Discovery loop for MIFARE Classic, uses POLL mode to detect the MIFARE Classic card.
 * Displays detected MIFARE Classic card information like UID, ATQA, SAK, Sector Authentication, Block Read and Write status.
 * Example will activate the device at index zero whenever multiple MIFARE Classic cards are detected.

 * Please refer Readme.txt file for Hardware Pin Configuration, Software Configuration and steps to build and
 * execute the project which is present in the same project directory.
 * $Author: $
 * $Revision: $ (v07.09.00)
 * $Date: $
 *
 */

/**
* Reader Library Headers
*/
#include <phApp_Init.h>

#include "NfcrdlibEx4_MIFAREClassic.h"



#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
**   Definitions
*******************************************************************************/


#define NUMBER_OF_KEYENTRIES        2
#define NUMBER_OF_KEYVERSIONPAIRS   2
#define NUMBER_OF_KUCENTRIES        1

#define DATA_BUFFER_LEN             16 /* Buffer length */
#define MFC_BLOCK_DATA_SIZE         16 /* Block Data size - 16 Bytes */

phacDiscLoop_Sw_DataParams_t       * pDiscLoop;       /* Discovery loop component */
void *psKeyStore;
void *psalMFC;

/*PAL variables*/
phKeyStore_Sw_KeyEntry_t           sKeyEntries[NUMBER_OF_KEYENTRIES];                                  /* Sw KeyEntry structure */
phKeyStore_Sw_KUCEntry_t           sKUCEntries[NUMBER_OF_KUCENTRIES];                                  /* Sw Key usage counter structure */
phKeyStore_Sw_KeyVersionPair_t     sKeyVersionPairs[NUMBER_OF_KEYVERSIONPAIRS * NUMBER_OF_KEYENTRIES]; /* Sw KeyVersionPair structure */

uint8_t                            bDataBuffer[DATA_BUFFER_LEN];  /* universal data buffer */
uint8_t                            val[4];
char input[20];
uint8_t buffr[] = {0,0,0,0};

uint8_t                            bSak;                      /* SAK  card type information */
uint16_t                           wAtqa;                     /* ATQA card type information */

/* Set the key for the MIFARE (R) Classic cards. */
uint8_t Key[12] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};

/* Don't change the following line. */
uint8_t Original_Key[12] = {0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU};

#ifdef PHOSAL_FREERTOS_STATIC_MEM_ALLOCATION
uint32_t aMfClassicTaskBuffer[MIFARECLASSIC_TASK_STACK];
#else /* PHOSAL_FREERTOS_STATIC_MEM_ALLOCATION */
#define aMfClassicTaskBuffer       NULL
#endif /* PHOSAL_FREERTOS_STATIC_MEM_ALLOCATION */

#ifdef PH_OSAL_FREERTOS
const uint8_t bTaskName[configMAX_TASK_NAME_LEN] = {"MfClassic"};
#else
const uint8_t bTaskName[] = {"MfClassic"};
#endif /* PH_OSAL_FREERTOS */

static volatile uint8_t bInfLoop = 1U;

/*******************************************************************************
**   Prototypes
*******************************************************************************/

void NfcrdlibEx4_MIFAREClassic(void *pParams);
static phStatus_t Ex4_NfcRdLibInit(void);

/*******************************************************************************
**   Code
*******************************************************************************/

int main(void)
{
    do
    {
		#ifdef PH_PLATFORM_HAS_ICFRONTEND
        	phNfcLib_AppContext_t AppContext = {0};
		#endif /* PH_PLATFORM_HAS_ICFRONTEND */

		#ifndef PH_OSAL_NULLOS
        	phOsal_ThreadObj_t MfClassic;
		#endif /* PH_OSAL_NULLOS */

        BOARD_InitBootPins();
        BOARD_InitBootClocks();
        BOARD_InitDebugConsole();

        /* Perform OSAL Initialization. */
        (void)phOsal_Init();

        /* Print Example application name */
        DEBUG_PRINTF("\n *** MIFARE Classic Example *** \n");


#ifdef PH_PLATFORM_HAS_ICFRONTEND
        phbalReg_Init(&sBalParams, sizeof(phbalReg_Type_t));

        AppContext.pBalDataparams = &sBalParams;
        dwStatus = phNfcLib_SetContext(&AppContext);
        CHECK_NFCLIB_STATUS(dwStatus);
#endif /* PH_PLATFORM_HAS_ICFRONTEND */

        /* Initialize library */
        phNfcLib_Init();

        /* Set the generic pointer */
        pHal = phNfcLib_GetDataParams(PH_COMP_HAL);
        pDiscLoop = phNfcLib_GetDataParams(PH_COMP_AC_DISCLOOP);
        psKeyStore = phNfcLib_GetDataParams(PH_COMP_KEYSTORE);
        psalMFC = phNfcLib_GetDataParams(PH_COMP_AL_MFC);

        /* Initialize other components that are not initialized by NFCLIB and configure Discovery Loop. */
        phApp_Comp_Init(pDiscLoop);

        phApp_Configure_IRQ();

#ifndef PH_OSAL_NULLOS

        MfClassic.pTaskName = (uint8_t *)bTaskName;
        MfClassic.pStackBuffer = aMfClassicTaskBuffer;
        MfClassic.priority = MIFARECLASSIC_TASK_PRIO;
        MfClassic.stackSizeInNum = MIFARECLASSIC_TASK_STACK;
        phOsal_ThreadCreate(&MfClassic.ThreadHandle, &MfClassic, &NfcrdlibEx4_MIFAREClassic, NULL);

        phOsal_StartScheduler();

        /* Print Error info */
        DEBUG_PRINTF("RTOS Error : Scheduler exited. \n");

#else
        (void)NfcrdlibEx4_MIFAREClassic(pDiscLoop);
#endif /* PH_OSAL_NULLOS */
    } while(0);

    while(bInfLoop); /* Comes here if initialization failure or scheduler exit due to error */

    return 0;
}

/***********************************************************************************************
 * \brief   This function demonstrates the MIFARE Classic card detection, Block authentication,
 *          Block Read and Block Write operation.
 * \param   *pParams
 * \return  This function will never return
 **********************************************************************************************/
void NfcrdlibEx4_MIFAREClassic(void *pParams)
{
    uint16_t    wTagsDetected = 0;
    uint8_t     bUid[PHAC_DISCLOOP_I3P3A_MAX_UID_LENGTH];
    uint8_t     bUidSize;

    /* This call shall allocate secure context before calling any secure function,
     * when FreeRtos trust zone is enabled.
     * */
    phOsal_ThreadSecureStack( 512 );


    while(1)    /* Continuous loop */
    {
    	wTagsDetected = 0;
    	Ex4_NfcRdLibInit();

        /* Field OFF */
        phhalHw_FieldOff(pHal);

        phhalHw_Wait(pDiscLoop->pHalDataParams,PHHAL_HW_TIME_MICROSECONDS, 5100);

        phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE, PHAC_DISCLOOP_POLL_STATE_DETECTION);

        phacDiscLoop_Run(pDiscLoop, PHAC_DISCLOOP_ENTRY_POINT_POLL);

        printf("Enter the case (1, 2 or 3): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
        	 // Input successfully read into 'input'
             // Now parse the input and convert to integers
             sscanf(input, "%d", &buffr[0]);

             // Now you can use the 'buffr' array
             printf("You entered: %d\n", buffr[0]);
         } else {
        	 // Error reading input
        	 printf("Error reading input.\n");
         }

         phalMfc_Write(psalMFC, 4, buffr);


         phalMfc_Read(psalMFC, 4, bDataBuffer);

         DEBUG_PRINTF("\nThe content of Block 4 is:\n");

         phApp_Print_Buff(&bDataBuffer[0], MFC_BLOCK_DATA_SIZE);
         DEBUG_PRINTF("\n\n --- End of Read Operation --- \n");

         phhalHw_FieldOn(pHal);
         phhalHw_Wait(pDiscLoop->pHalDataParams,PHHAL_HW_TIME_MICROSECONDS, 5100);
    }
}

/***********************************************************************************************
 * \brief   Initializes the discovery loop and keystore components required by Example-4
 * \param   none
 * \return  status  Returns the function status
 **********************************************************************************************/
static phStatus_t Ex4_NfcRdLibInit(void)
{
    phStatus_t status;

    /* Device limit for Type A */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT, 1);
    CHECK_STATUS(status);

    /* Bailout on Type A detect */
    status = phacDiscLoop_SetConfig(pDiscLoop, PHAC_DISCLOOP_CONFIG_BAIL_OUT, PHAC_DISCLOOP_POS_BIT_MASK_A);
    CHECK_STATUS(status);

    /* Initialize the keystore component */
    status = phKeyStore_Sw_Init(
        psKeyStore,
        sizeof(phKeyStore_Sw_DataParams_t),
        &sKeyEntries[0],
        NUMBER_OF_KEYENTRIES,
        &sKeyVersionPairs[0],
        NUMBER_OF_KEYVERSIONPAIRS,
        &sKUCEntries[0],
        NUMBER_OF_KUCENTRIES
        );
    CHECK_STATUS(status);

    /* load a Key to the Store */
    /* Note: If You use Key number 0x00, be aware that in SAM
      this Key is the 'Host authentication key' !!! */
    status = phKeyStore_FormatKeyEntry(psKeyStore, 1, PH_KEYSTORE_KEY_TYPE_MIFARE);
    CHECK_STATUS(status);

    /* Set Key Store */
    status = phKeyStore_SetKey(psKeyStore, 1, 0, PH_KEYSTORE_KEY_TYPE_MIFARE, &Key[0], 0);
    CHECK_STATUS(status);

    /* Read the version of the reader IC */
#if defined NXPBUILD__PHHAL_HW_RC663
    status = phhalHw_Rc663_ReadRegister(pHal, PHHAL_HW_RC663_REG_VERSION, &bDataBuffer[0]);
    CHECK_STATUS(status);
    DEBUG_PRINTF("\nReader chip RC663: 0x%02x\n", bDataBuffer[0]);
#endif /* NXPBUILD__PHHAL_HW_RC663 */

    /* Return Success */
    return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PHHAL_HW_TARGET
/* Stubbed definitions in case TARGET is enabled */
uint8_t  sens_res[2]     = {0x04, 0x00};
uint8_t  nfc_id1[3]      = {0xA1, 0xA2, 0xA3};
uint8_t  sel_res         = 0x40;
uint8_t  nfc_id3         = 0xFA;
uint8_t  poll_res[18]    = {0x01, 0xFE, 0xB2, 0xB3, 0xB4, 0xB5,
                                   0xB6, 0xB7, 0xC0, 0xC1, 0xC2, 0xC3,
                                   0xC4, 0xC5, 0xC6, 0xC7, 0x23, 0x45 };
#endif /* NXPBUILD__PHHAL_HW_TARGET */
