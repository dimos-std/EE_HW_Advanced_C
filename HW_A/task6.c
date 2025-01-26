// инверсия битов старшего байта
#include <stdio.h>
#include <inttypes.h>

#define HIGH_BYTE ((uint32_t)0xFF << 24)
int main(void)
{
    uint32_t value;

    scanf("%" SCNu32, &value);
    value ^= HIGH_BYTE;
    printf("%" PRIu32 "\n", value);
    return 0;
}
