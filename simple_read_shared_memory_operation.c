#include "board.h"

int main(void)
{
    Board_Init();
    NSS_NFC->CFG = 0;
    NSS_NFC->BUF[0] = 2;
    NSS_NFC->BUF[1] = 3;

    if (NSS_NFC->BUF[0] == 2)
	NSS_NFC->BUF[2]= NSS_NFC->BUF[0] + NSS_NFC->BUF[1];

    return 0;
}