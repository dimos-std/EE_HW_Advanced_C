// найти число, встречающееся один раз

#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    uint32_t N, value, res;
    N = value = res = 0;
    scanf("%" SCNu32, &N);
    if (N <= 1000000)
    {
        for (uint32_t i = 0; i < N; i++)
        {
            scanf("%" SCNu32, &value);
            res ^= value;
        }
        printf("%" PRIu32 "\n", res);
    }
    return 0;
}
