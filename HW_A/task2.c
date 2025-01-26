// циклический сдви бит в числе
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t rotate, value;

    scanf("%" SCNu32"%"SCNu32, &value, &rotate);
    if (rotate > 0 && rotate < 32)
    {
        value = (value >> rotate) | (value << (32 - rotate));
        printf("%" PRIu32 "\n", value);
    }
}
