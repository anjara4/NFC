Getting started with PN7642 reader and NHS3152 
I use the program "pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub" from the SDK example.
The program can read and write the NFC MIFARE Classic Card (white card)
But the program cannot read or write the NHS3152.

pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub setup:
1) Install the SDK: "PN7642_MCUXpresso_SDK_02-12-05_PUB"
2) Install example from the SDK: boards/pnev7642fama/nfc_examples/NfcrdlibEx4_MIFAREClassic
3) Allow Debug print: Miscellaneous/Quick Settings/SDK Degub Console/ select "Semihost console"
4) Build and Debug
5) Run / Step Over (F6) 

The problem is related to the fact that NFC MIFARE Classic Card require an authentification in order to be manipulated by other reader.
And the NHS3152 does not require an authentification.
The solution for me is to comment all the authentification part of the original code.
Note, with this solution, a MIFARE Classic Card can no longer work with this programm.

In the commit 1: 
1) Remove the authentification
    a) Row 233:  /* Check for MIFARE Classic */
                        //if (0x08 == (pDiscLoop->sTypeATargetInfo.aTypeA_I3P3[0].aSak & 0x08)){
   
    b) Row 254: /* Authenticate with the Key */
                       //status = phalMfc_Authenticate(psalMFC, 6, PHHAL_HW_MFC_KEYA, 1, 0, bUid, bUidSize);
                        /* Check for Status */
                        /*if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS){
                            // Print Error info
                            DEBUG_PRINTF("\nAuthentication Failed!!!");
                            DEBUG_PRINTF("\nPlease correct the used key");
                            DEBUG_PRINTF("\nExecution aborted!!!\n");
                            break;
                        }
                        DEBUG_PRINTF("\nAuthentication Successful");*/
   
3) Read the memory from the block 4, Write the block 5 with val="77", Read again the memory from the block 4
The resultat is found on the screenshot ScreenShot_ReadWrite_PN7642_NHS3152.png
The problem here:
1) The programm writes each character in a different colomn and adds 3 at the begening of each colomn
2) There is too much debug and step over(step 5 of the program setup) and steps before the programm can read and write

Task:
1) Interaction with the console (Done)
2) Structuration du code (remove all unnecessary information)
3) Run the code that turns the light with different configuration (Done)
4) Implementation GUI
5) Set the intenisty of the NFC Field
