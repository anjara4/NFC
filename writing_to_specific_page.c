#include "chip.h"

int main(void)
{
    NSS_NFC->CFG = 0;
    NSS_NFC->BUF[0] = 12;

    return 0;
}

