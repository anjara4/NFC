#include "chip.h"

int main(void)
{
    NSS_NFC->CFG = 0;
    NSS_NFC->BUF[0] = 12; // This initiates 12 into the 4th page. The 4th page is the fist page for data

    return 0;
}

