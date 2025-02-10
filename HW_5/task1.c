// Посчитать количество комбинаций вычеркивая цифры
#include <stdio.h>

int count_combinations(int, int *);

int main(void)
{
    int arr[1000];
    int arr_size = 0;
    char ch = 0;

    while ((ch = getchar()) != '\n')
        if (ch >= '0' && ch <= '9')
            arr[arr_size++] = ch - '0';

    printf("%d\n", count_combinations(arr_size, arr));
    return 0;
}

int count_combinations(int arr_size, int *arr)
{
    int numbers[1000] = {0};
    int cnt = 0;

    for (int i = 0; i < arr_size - 2; i++)
    {
        int hundreds = 100 * arr[i];
        for (int j = i + 1; j < arr_size - 1; j++)
        {
            int tens = 10 * arr[j];
            for (int k = j + 1; k < arr_size; k++)
                numbers[hundreds + tens + arr[k]] = 1;
        }
    }

    for (int i = 100; i < 1000; i++)
    {
        if (numbers[i])
            cnt++;
    }
    return cnt;
}