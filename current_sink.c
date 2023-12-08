#include "board.h"

int main(void){
    Board_Init();
    Chip_GPIO_Init(NSS_GPIO);
    Chip_IOCON_Init(NSS_IOCON);

    int current_low_uA = 500;     // 0.5mA
    int current_high_uA = 3500;     // 3.5mA
    char LED = IOCON_PIO0_3; //PIN3 and PIN7 can be used if setting the intensity
    //Current sink: VDD -> (+)LED(-) -> PIN3 -> 0 (low)

    //(current * 255) / 20000) -> Intesity discretisation
    Chip_IOCON_SetPinConfig(NSS_IOCON, LED, IOCON_FUNC_0 | 
                                            IOCON_RMODE_INACT | 
                                            IOCON_LPF_DISABLE | 
                                            IOCON_CDRIVE_PROGRAMMABLECURRENT| 
                                            IOCON_ILO_VAL((current_low_uA * 255) / 20000) /* current_min uA low */| 
                                            IOCON_IHI_VAL((current_high_uA * 255) / 20000) /* current_max uA high */
	                   );
    Chip_GPIO_SetPinDIROutput(NSS_GPIO, 0, LED);
    Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, LED); //to get current_low mA through the load

    return 0;
}

