// подсчет количества едичное количество бит
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    uint32_t value, cnt = 0;

    scanf("%" SCNu32, &value);

    for (uint32_t i = 0; i < 32; i++)
        if ((value >> i) & 1)
            cnt++;
    printf("%" PRIu32 "\n", cnt);
    return 0;
}
