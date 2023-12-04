# Writing data from an NFC Reader RC522 to an NHS3152 nxp chip
This code is inspired by https://devcraze.com/tutorials/arduino/mfrc522-rfid-read-and-write-data-in-specific-rfid-block/
The original code can be used to write data into an Mifair card but cannot work whith the NHS3152 chip
The problem is that the authenfication for the Mifair card does not work with the NHS3152 chip
Mifair need to be authentified in order to work
My initial solution is to remove the authentication phase, which is not mandatory with the NHS3152 (obviously)
The next step will be to add the authentification for the NHS3152
