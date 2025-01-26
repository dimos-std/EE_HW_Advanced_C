// вывести произвольное количество младших бит
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t bits, value;

    scanf("%" SCNu32 "%" SCNu32, &value, &bits);
    if (bits > 0 && bits < 32)
    {
        value &= ((1 << bits) - 1);
        printf("%" PRIu32 "\n", value);
    }
    return 0;
}