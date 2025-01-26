// получить значение степени переменной float

#include <stdio.h>
#include <inttypes.h>

typedef union
{
    float value;
    struct
    {
        uint32_t mant : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
    } bit;
} float_bit_t;

int extractExp(float num)
{
    float_bit_t float_bit;
    float_bit.value = num;
    return (int)float_bit.bit.exp;
}

int main(void)
{
    float num = 0;
    int exp;

    scanf("%f", &num);
    exp = extractExp(num);
    printf("%d\n", exp);

    return 0;
}
