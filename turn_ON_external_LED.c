#include "board.h"

int main(void)
{
   Board_Init();
   Chip_GPIO_Init(NSS_GPIO);
   Chip_IOCON_Init(NSS_IOCON);

   Chip_IOCON_SetPinConfig(NSS_IOCON, IOCON_PIO0_2 , IOCON_FUNC_0 | IOCON_RMODE_PULLUP | IOCON_LPF_DISABLE);
   Chip_GPIO_SetPinDIROutput(NSS_GPIO, 0, IOCON_PIO0_2);
   Chip_GPIO_SetPinOutHigh(NSS_GPIO, 0, IOCON_PIO0_2);
   //Chip_GPIO_SetPinOutLow(NSS_GPIO, 0, IOCON_PIO0_2);
   return 0;
}
