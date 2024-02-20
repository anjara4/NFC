/*----------------------------------------------------------------------------*/
/* Copyright 2022 NXP                                                         */
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
* PN76XX KeyStore Component of Reader Library Framework.
* $Author: Rajendran Kumar (nxp99556) $
* $Revision: 6424 $ (v07.09.00)
* $Date: 2021-10-05 23:02:00 +0530 (Tue, 05 Oct 2021) $
*
* History:
*  CHu: Generated 23. Jun 2022
*
*/

#include <ph_Status.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PH_KEYSTORE_PN76XX

#include "phKeyStore_PN76XX.h"

phStatus_t phKeyStore_PN76XX_Init(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wSizeOfDataParams,
     phKeyStore_PN76XX_KeyEntry_t * pKeyEntries, uint16_t wNoOfKeyEntries)
{
    uint8_t     PH_MEMLOC_REM bIndex = 0;

    if(sizeof(phKeyStore_PN76XX_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
    }
    PH_ASSERT_NULL(pDataParams);
    PH_ASSERT_NULL(pKeyEntries);

    /* Init private data */
    pDataParams->wId                  = PH_COMP_KEYSTORE | PH_KEYSTORE_PN76XX_ID;
    pDataParams->pKeyEntries          = pKeyEntries;
    pDataParams->wNoOfKeyEntries      = wNoOfKeyEntries;

    for(bIndex = 0; bIndex < pDataParams->wNoOfKeyEntries; bIndex++)
    {
        pDataParams->pKeyEntries[bIndex].wKeyType     = PH_KEYSTORE_INVALID_ID;
        pDataParams->pKeyEntries[bIndex].bKeyIndex    = (uint8_t) PH_KEYSTORE_INVALID_ID;
        pDataParams->pKeyEntries[bIndex].bKeyLen      = 0;

    }

    return PH_ERR_SUCCESS;
}

phStatus_t phKeyStore_PN76XX_DeInit(phKeyStore_PN76XX_DataParams_t * pDataParams)
{
    uint8_t     PH_MEMLOC_REM bIndex = 0;

    for(bIndex = 0; bIndex < pDataParams->wNoOfKeyEntries; bIndex++)
    {
        pDataParams->pKeyEntries[bIndex].wKeyType     = PH_KEYSTORE_INVALID_ID;
        pDataParams->pKeyEntries[bIndex].bKeyIndex    = (uint8_t) PH_KEYSTORE_INVALID_ID;
        pDataParams->pKeyEntries[bIndex].bKeyLen      = 0;

    }
    pDataParams->wNoOfKeyEntries = 0U;

    return PH_ERR_SUCCESS;
}





/* Common Interfaces ------------------------------------------------------------------------------------------------------------------- */
phStatus_t phKeyStore_PN76XX_FormatKeyEntry(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyNo, uint16_t wNewKeyType)
{
    /* Overflow checks */
    if(wKeyNo >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    switch(wNewKeyType)
    {
        case PH_KEYSTORE_KEY_TYPE_AES128:
        case PH_KEYSTORE_KEY_TYPE_AES256:
        case PH_KEYSTORE_KEY_TYPE_DES:
        case PH_KEYSTORE_KEY_TYPE_2K3DES:
        case PH_KEYSTORE_KEY_TYPE_3K3DES:
        case PH_KEYSTORE_KEY_TYPE_MIFARE:

            /* Nothing to do here. */
            break;

        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    pDataParams->pKeyEntries[wKeyNo].wKeyType = wNewKeyType;
    (void) memset(pDataParams->pKeyEntries[wKeyNo].aKey, 0x00, PH_KEYSTORE_MAX_KEY_SIZE);

    return PH_ERR_SUCCESS;
}

phStatus_t phKeyStore_PN76XX_SetKUC(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyNo, uint16_t wRefNoKUC)
{
    /* Satisfy compiler */
    if(pDataParams || wKeyNo || wRefNoKUC)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_GetKUC(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wRefNoKUC, uint32_t * pdwLimit,
    uint32_t * pdwCurVal)
{
    /* Satisfy compiler */
    if(pDataParams || wRefNoKUC || pdwLimit || pdwCurVal)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_ChangeKUC(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wRefNoKUC, uint32_t dwLimit)
{
    /* Satisfy compiler */
    if(pDataParams || wRefNoKUC || dwLimit)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_SetConfig(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wConfig, uint16_t wValue)
{
    /* Satisfy compiler */
    if(pDataParams || wConfig || wValue)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_SetConfigStr(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wConfig, uint8_t *pBuffer,
    uint16_t wBufferLength)
{
    /* Satisfy compiler */
    if(pDataParams || wConfig || pBuffer || wBufferLength)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_GetConfig(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wConfig, uint16_t * pValue)
{
    /* Satisfy compiler */
    if(pDataParams || wConfig || pValue)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_GetConfigStr(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wConfig, uint8_t ** ppBuffer,
    uint16_t * pBufferLength)
{
    /* Satisfy compiler */
    if(pDataParams || wConfig || ppBuffer || pBufferLength)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}





/* Interfaces for Symmetric Keys ------------------------------------------------------------------------------------------------------- */
phStatus_t phKeyStore_PN76XX_SetKey(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyNo, uint16_t wKeyVer,
    uint16_t wKeyType, uint8_t * pNewKey, uint16_t wNewKeyVer)
{
    /* Satisfy the compiler. */
    if(wKeyVer)
    {
        ;/* Do nothing */
    }

    return phKeyStore_PN76XX_SetKeyAtPos(pDataParams, wKeyNo, pDataParams->pKeyEntries[wKeyNo].bKeyIndex, wKeyType, pNewKey, wNewKeyVer);
}

phStatus_t phKeyStore_PN76XX_SetKeyAtPos(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyNo, uint16_t wPos, uint16_t wKeyType,
    uint8_t * pNewKey, uint16_t wNewKeyVer)
{
    phStatus_t  PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;

    /* Satisfy the compiler. */
    if(wNewKeyVer)
    {
        ;/* Do nothing */
    }

    /* Overflow checks */
    if(wKeyNo >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* Check that Key type matches with current Key Type format */
    if(pDataParams->pKeyEntries[wKeyNo].wKeyType != wKeyType)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* Load the Key */
    switch(wKeyType)
    {
        case PH_KEYSTORE_KEY_TYPE_AES128:
            /* Update the Key Index. */
            pDataParams->pKeyEntries[wKeyNo].bKeyIndex = (uint8_t) wPos;
            break;

        case PH_KEYSTORE_KEY_TYPE_AES256:
            /* Update the Key Index. */
            pDataParams->pKeyEntries[wKeyNo].bKeyIndex = (uint8_t) wPos;
            break;

        case PH_KEYSTORE_KEY_TYPE_DES:
        case PH_KEYSTORE_KEY_TYPE_2K3DES:
        case PH_KEYSTORE_KEY_TYPE_3K3DES:
        case PH_KEYSTORE_KEY_TYPE_MIFARE:
            /* Get the Key size. */
            pDataParams->pKeyEntries[wKeyNo].bKeyLen = phKeyStore_GetKeySize(wKeyType);
            pDataParams->pKeyEntries[wKeyNo].bKeyIndex = (uint8_t) PH_KEYSTORE_INVALID_ID;

            /* Copy the Key to DataParams. */
            (void) memcpy(pDataParams->pKeyEntries[wKeyNo].aKey, pNewKey, pDataParams->pKeyEntries[wKeyNo].bKeyLen);
            break;

        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    return wStatus;
}

phStatus_t phKeyStore_PN76XX_SetFullKeyEntry(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wNoOfKeys, uint16_t wKeyNo,
    uint16_t wNewRefNoKUC, uint16_t wNewKeyType, uint8_t * pNewKeys, uint16_t * pNewKeyVerList)
{
    /* Satisfy compiler */
    if(pDataParams || wNoOfKeys || wKeyNo || wNewRefNoKUC || wNewKeyType || pNewKeys || pNewKeyVerList)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_GetKeyEntry(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyNo, uint16_t wKeyVerBufSize,
    uint16_t * wKeyVer, uint16_t * wKeyVerLen, uint16_t * pKeyType)
{
    /* Satisfy compiler */
    if(pDataParams || wKeyNo || wKeyVerBufSize || wKeyVer || wKeyVerLen || pKeyType)
    {
        ;/* Do Nothing */
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}

phStatus_t phKeyStore_PN76XX_GetKey(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyNo, uint16_t wKeyVer, uint8_t bKeyBufSize,
    uint8_t * pKey, uint16_t * pKeyType)
{
    uint8_t     PH_MEMLOC_REM bCount = 0;

    /* Overflow checks */
    if(wKeyNo >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* Overflow checks */
    if(bKeyBufSize < pDataParams->pKeyEntries[wKeyNo].bKeyLen)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_KEYSTORE);
    }

    /* Set the Key Type. */
    *pKeyType = pDataParams->pKeyEntries[wKeyNo].wKeyType;

    /* Set the Key. */
    switch(*pKeyType)
    {
        case PH_KEYSTORE_KEY_TYPE_AES128:
        case PH_KEYSTORE_KEY_TYPE_AES256:
            pKey[bCount++] = 'K'; pKey[bCount++] = 'I'; pKey[bCount++] = 'D';
            pKey[bCount++] = pDataParams->pKeyEntries[wKeyNo].bKeyIndex;
            break;

        case PH_KEYSTORE_KEY_TYPE_DES:
        case PH_KEYSTORE_KEY_TYPE_2K3DES:
        case PH_KEYSTORE_KEY_TYPE_3K3DES:
        case PH_KEYSTORE_KEY_TYPE_MIFARE:
            /* Copy the Key to DataParams. */
            (void) memcpy(pKey, pDataParams->pKeyEntries[wKeyNo].aKey, pDataParams->pKeyEntries[wKeyNo].bKeyLen);
            break;

        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    return PH_ERR_SUCCESS;
}

phStatus_t phKeyStore_PN76XX_CheckUpdateKUC(phKeyStore_PN76XX_DataParams_t * pDataParams, uint16_t wKeyUsageCtrNo)
{
    /* Satisfy compiler */
    if(pDataParams || wKeyUsageCtrNo)
    {
        ; /*Do Nothing*/
    }

    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_KEYSTORE);
}











#endif /* NXPBUILD__PH_KEYSTORE_PN76XX */
