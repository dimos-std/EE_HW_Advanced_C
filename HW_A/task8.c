#include <stdio.h>

#define MAX_WEIGHT 1000000

int is_possible_weight(int weight, int max_weight)
{
    int bowl_left, bowl_right, cur_weight;
    int cnt;
    int remainder;

    if (weight <= max_weight)
    {
        bowl_left = weight;
        bowl_right = 0;
        cur_weight = 1;
        cnt = 0;

        while (weight > 0)
        {
            remainder = weight % 3;
            if (remainder == 2)
            {
                bowl_left += cur_weight;
                weight += 1;
                cnt++;
                // printf("-%d ", cur_weight);
            }
            else if (remainder == 1)
            {
                bowl_right += cur_weight;
                cnt++;
                // printf("%d ", cur_weight);
            }
            weight /= 3;
            cur_weight *= 3;
        }
        // printf("\n");
        if (bowl_left != bowl_right)
            cnt = -1;
        else if (bowl_left > MAX_WEIGHT || bowl_right > MAX_WEIGHT)
            cnt = -1;
    }
    else
        cnt = -1;

    return cnt;
}

int main(void)
{
    int weight = 0;
    scanf("%d", &weight);
    printf("%d\n", is_possible_weight(weight, MAX_WEIGHT));

    return 0;
}