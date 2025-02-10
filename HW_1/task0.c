// сколько раз встречается максимум в последовательности из N чисел
#include <stdio.h>
#include <limits.h>


int main(void)
{
    int N, cnt = 1;
    int val_max;
    int val;

    scanf("%d", &N);
    if (N > 0)
    {
        scanf("%d", &val_max);

        for (int i = 1; i < N; i++)
        {
            scanf("%d", &val);
            if (val > val_max)
            {
                val_max = val;
                cnt = 1;
            }
            else if (val == val_max)
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}