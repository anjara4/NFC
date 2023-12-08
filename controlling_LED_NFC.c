#include "board.h"

void setScenario(char);
void setPWM(double, double, char);
void setIntensity(int, int, char);

int main(void)
{
Board_Init();
    Chip_NFC_Init(NSS_NFC);

	NSS_NFC->CFG = 0;
	Chip_GPIO_Init(NSS_GPIO);
	Chip_IOCON_Init(NSS_IOCON);

	char LED = IOCON_PIO0_3;

	while(true){
		setScenario(LED);
	}
    return 0;
}

void setScenario(char LED){
	switch (NSS_NFC->BUF[0]) {
        case 1:
        	setIntensity(1000, 0, LED);
        	setPWM(500, 500, LED);
        	break;
        case 2:
        	setIntensity(500, 0, LED);
        	setPWM(50, 450, LED);
        	break;
        default:
    		setIntensity(1000, 0, LED);
    		setPWM(990, 10, LED);
            break;
    }
}

void setIntensity(int current_low, int current_high, char pin_name){// in µA (500µA = 0.5mA)
	Chip_IOCON_SetPinConfig(NSS_IOCON, pin_name, IOCON_FUNC_0 |
	   		                                     IOCON_RMODE_INACT |
												 IOCON_LPF_DISABLE |
												 IOCON_CDRIVE_PROGRAMMABLECURRENT |
												 IOCON_ILO_VAL(current_low * 255 / 20000) |
												 IOCON_IHI_VAL(current_high * 255 / 20000)
												 );
	Chip_GPIO_SetPinDIROutput(NSS_GPIO, 0, pin_name);
	Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, pin_name); //to get current_low mA through the load
}

void setPWM(double TimeH, double TimeL, char pin_name){
	Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, pin_name);
    Chip_Clock_System_BusyWait_ms(TimeH);
    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, pin_name);
    Chip_Clock_System_BusyWait_ms(TimeL);
}

