Overview
========
This example will demonstrates the MIFARE Classic card detection, Block authentication,Block Read and Block Write operation.

Toolchain supported
===================
- IAR embedded Workbench  9.32.1
- Keil MDK  5.37
- GCC ARM Embedded  10.3.1
- MCUXpresso  11.7.0

Hardware requirements
=====================
- USB Type-C cable
- PNEV7642FAMA board
- Personal Computer
- MIFARE Classic card

Board settings
==============
1. Set the J3 jumper to select the proper power supply. For example, to use USB
   USB Type-C cable as power supply, then short J3 2-3, and connect USB Type-C
   cable to port J5.
2. Connect J-Link to J21.

Prepare the Demo
================
1.  Open SEGGER RTT Viewer, select device "PN7642" and target interface SWD.
    For RTT control block searching, select Address 0x20008000
2.  Download the program to the target board.
3.  Click "Run" in IDE to run the application.

Running the demo
================
The log below shows the output of the NfcrdlibEx4_MIFAREClassic demo in the RTT Viewer.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Enhanced Contactless Polling(ECP) Example: 

 *** MIFARE Classic Example *** 

Ready to detect
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
After above log print out, the demo start to polling the detection of MIFARE Classic card, please place a card near the PNEV7642FAMA ANTENNA. When the card been recognized, below information will be printed
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
UID:  xx xx xx
ATQA: xx xx
SAK: xx
Product: MIFARE Classic 

Authentication Successful
Read data from Block 4
Read Success
The content of Block 4 is:
 xx xx xx xx xx xx xx xx 

 --- End of Read Operation --- 

Write data to Block 4
Write Success

 --- End of Write Operation --- 

 --- End of Example --- 


Please Remove the Card
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
