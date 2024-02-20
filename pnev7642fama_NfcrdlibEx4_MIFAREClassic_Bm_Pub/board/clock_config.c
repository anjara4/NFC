/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/
/*
 * Clock initialization functions.
 */

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Clocks v10.0
processor: PN7642
package_id: PN7642EV
mcu_data: ksdk2_0
processor_version: 0.12.1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

#include "fsl_clock.h"
#include "fsl_power.h"
#include "PN76_Eeprom.h"
#include "clock_config.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 ************************ BOARD_InitBootClocks function ************************
 ******************************************************************************/
void BOARD_InitBootClocks(void)
{
    BOARD_BootClockRUN();
}

/*******************************************************************************
 ********************** Configuration BOARD_BootClockRUN ***********************
 ******************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!Configuration
name: BOARD_BootClockRUN
called_from_default_init: true
outputs:
- {id: CLK_FLASH.outFreq, value: 45 MHz}
- {id: CLK_HFO.outFreq, value: 90 MHz}
- {id: CLK_LFO.outFreq, value: 380 kHz}
- {id: CLK_PCRM_ARNG.outFreq, value: 2.8125 MHz}
- {id: CLK_PCRM_HOSTIF_UART.outFreq, value: 90 MHz}
- {id: CLK_PCRM_LPUART.outFreq, value: 90 MHz}
- {id: CLK_ULFO.outFreq, value: 1 kHz}
- {id: SYSTEM_1_CLK.outFreq, value: 45 MHz}
- {id: SYSTEM_2_CLK.outFreq, value: 45 MHz}
settings:
- {id: ClifPllConfig, value: 'no'}
- {id: USBPLLConfig, value: 'no'}
- {id: PCRM.SYS_CLK_SRC_SEL.sel, value: PCRM.cpm_div_hfo_45M}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/*******************************************************************************
 * Variables for BOARD_BootClockRUN configuration
 ******************************************************************************/

/*******************************************************************************
 * Code for BOARD_BootClockRUN configuration
 ******************************************************************************/
void BOARD_BootClockRUN(void)
{
    PN76_Status_t status;
    (void)status; // suppress warning in the run configuration
    uint8_t bValue;
    /* Initialize Power Management Unit (PMU) */
    PMU_Init();
    /* Initialize System Management Unit (SMU) */
    SMU_Init();
    /* Select the system clock source frequency. */
    /* Read the HFO System clock source selection configuration from EEPROM. */
    status = PN76_ReadEeprom(&bValue, PN76_HFO_SYS_CLK_SRC_SEL_ADDR, sizeof(uint8_t), E_PN76_EEPROM_IC_CONFIG);
    assert(status == PN76_STATUS_SUCCESS);
    if (bValue != 1U)
    {
        bValue = 1U;
        status = PN76_WriteEeprom(&bValue, PN76_HFO_SYS_CLK_SRC_SEL_ADDR, sizeof(uint8_t), E_PN76_EEPROM_IC_CONFIG);
        assert(status == PN76_STATUS_SUCCESS);
    }
    /* Select the GPADC clock source. */
    /* Read the GPADC clock source selector configuration from EEPROM. */
    status = PN76_ReadEeprom(&bValue, PN76_GPADC_CLK_SRC_SEL_ADDR, sizeof(uint8_t), E_PN76_EEPROM_IC_CONFIG);
    assert(status == PN76_STATUS_SUCCESS);
    if (bValue != 1U)
    {
        bValue = 1U;
        status = PN76_WriteEeprom(&bValue, PN76_GPADC_CLK_SRC_SEL_ADDR, sizeof(uint8_t), E_PN76_EEPROM_IC_CONFIG);
        assert(status == PN76_STATUS_SUCCESS);
    }
    /* Initialize the clock generating, system clock and the XTAL if selected as the CLIF clock source. */
    CLOCK_InitClockGeneration();
    /* Select the UART clock source. */
    CLOCK_SetLpuartClk(0, kCLOCK_LpuartSrcHfo);
    /* System core clock frequency global variable initialization for the SDK clock driver. */
    SystemCoreClock = CLOCK_GetCoreSysClkFreq();
}