// найти максимальное значнение из произвольного кооличества бит
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t bits, value;
    uint32_t max, tmp;

    scanf("%" SCNu32 "%" SCNu32, &value, &bits);
    if (bits > 0 && bits < 32)
    {
        max = value & ((1 << bits) - 1);
        for (uint32_t i = 1; i <= (32 - bits); i++)
        {
            tmp = (value >> i) & ((1 << bits) - 1);
            if (max < tmp)
                max = tmp;
        }
        printf("%" PRIu32 "\n", max);
    }
}