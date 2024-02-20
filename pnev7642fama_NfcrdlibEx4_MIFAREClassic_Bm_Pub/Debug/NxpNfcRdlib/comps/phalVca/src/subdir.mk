################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NxpNfcRdlib/comps/phalVca/src/phalVca.c \
../NxpNfcRdlib/comps/phalVca/src/phalVca_Int.c 

C_DEPS += \
./NxpNfcRdlib/comps/phalVca/src/phalVca.d \
./NxpNfcRdlib/comps/phalVca/src/phalVca_Int.d 

OBJS += \
./NxpNfcRdlib/comps/phalVca/src/phalVca.o \
./NxpNfcRdlib/comps/phalVca/src/phalVca_Int.o 


# Each subdirectory must supply rules for building sources it contributes
NxpNfcRdlib/comps/phalVca/src/%.o: ../NxpNfcRdlib/comps/phalVca/src/%.c NxpNfcRdlib/comps/phalVca/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_PN7642EV -D__PN76XX__=1 -D__PN7642__=1 -DNXPBUILD_CUSTOMER_HEADER_INCLUDED -DPH_OSAL_NULLOS -DMCUXPRESSO_SDK -DSEGGER_RTT_SECTION='"._SEGGER_RTT"' -DSEGGER_RTT_BUFFER_SECTION='"._SEGGER_RTT_BUFFER"' -DCPU_PN7642EV_cm33_nodsp -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSDK_DEBUGCONSOLE=0 -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\source" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phhalHw\src\PN76xx" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\components\phOsal\inc" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\components\phOsal\src\NullOs" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\components\phOsal\src\NullOs\portable" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\components\DAL\inc" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\components\CLIF" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\device\hal_intfs\inc" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\drivers" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p3a\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p3a\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfc\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfc\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalMifare\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalMifare\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phacDiscLoop\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phNfcLib\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phTools\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\types" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\intfs" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phKeyStore\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phKeyStore\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\device" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\utilities" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\CMSIS" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p4\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p4\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalFelica\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalFelica\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalSli15693\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalSli15693\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p3b\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p3b\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p4a\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI18092mPI\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI18092mPI\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalI18000p3m3\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalI18000p3m3" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI18000p3m3\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI18000p3m3\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalT1T\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phCryptoRng\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phCryptoRng\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phCryptoSym\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phCryptoSym\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phceT4T\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phceT4T\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p4mC\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI14443p4mC\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phlnLlcp\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phlnLlcp\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI18092mT\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalI18092mT\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalTop\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMful\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMful\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalFelica\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalFelica" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfdf\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfdf\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalICode\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalICode\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfNtag42XDna\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfNtag42XDna\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phTMIUtils\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalVca\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalVca\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfdfEVx\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfdfEVx\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfpEVx\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfpEVx\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfdfLight\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phalMfdfLight\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalEpcUid\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phpalEpcUid\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phnpSnep\src\Sw" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\NxpNfcRdlib\comps\phnpSnep\src" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\rtt\RTT" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\board" -I"C:\Users\NobbyXP\Documents\NHS3152\NFC\pnev7642fama_NfcrdlibEx4_MIFAREClassic_Bm_Pub\pnev7642fama\nfc_examples\NfcrdlibEx4_MIFAREClassic" -O0 -fno-common -g3 -gdwarf-4 -mcpu=cortex-m33+nodsp+nofp -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33+nodsp -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-NxpNfcRdlib-2f-comps-2f-phalVca-2f-src

clean-NxpNfcRdlib-2f-comps-2f-phalVca-2f-src:
	-$(RM) ./NxpNfcRdlib/comps/phalVca/src/phalVca.d ./NxpNfcRdlib/comps/phalVca/src/phalVca.o ./NxpNfcRdlib/comps/phalVca/src/phalVca_Int.d ./NxpNfcRdlib/comps/phalVca/src/phalVca_Int.o

.PHONY: clean-NxpNfcRdlib-2f-comps-2f-phalVca-2f-src

