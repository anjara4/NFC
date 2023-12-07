#include "board.h"

int main(void)
{
	Board_Init();
	NSS_NFC->CFG = 0;
	Chip_GPIO_Init(NSS_GPIO);
	Chip_IOCON_Init(NSS_IOCON);

	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_1 , IOCON_FUNC_0 | IOCON_RMODE_PULLUP | IOCON_LPF_DISABLE);
	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_2 , IOCON_FUNC_0 | IOCON_RMODE_PULLUP | IOCON_LPF_DISABLE);
	Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_3 , IOCON_FUNC_0 | IOCON_RMODE_PULLUP | IOCON_LPF_DISABLE);

	Chip_GPIO_SetPinDIROutput(NSS_GPIO, 0, IOCON_PIO0_1);
	Chip_GPIO_SetPinDIROutput(NSS_GPIO, 0, IOCON_PIO0_2);
	Chip_GPIO_SetPinDIROutput(NSS_GPIO, 0, IOCON_PIO0_3);

	while(true){
		if(NSS_NFC->BUF[0] == 0){
			Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_1);//red led
		   	Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_2);//green led
		   	Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_3);//yellow led
		}
		else if(NSS_NFC->BUF[0] == 1){
		    Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_1);//red led

		    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_2);//green led
		    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_3);//yellow led
		}
		else if(NSS_NFC->BUF[0] == 2){
			Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_2);//green led

		    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_1);//red led
		    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_3);//yellow led
		}
		else if(NSS_NFC->BUF[0] == 3){
		    Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_3);//yellow led

		    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_1);//red led
		    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_2);//green led
		}
		else{
		    Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_1);//red led
		    Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_2);//green led
		    Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_3);//yellow led
		}
	}

    return 0;
}
