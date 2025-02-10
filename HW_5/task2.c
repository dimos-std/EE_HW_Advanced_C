#include <stdio.h>
#include <string.h>

#define STR_MAX_SIZE 1000

int min(int, int);
void zFunction2(char *, int *);
int max_suffix(char *, char *);

int main(void)
{
    char str1[STR_MAX_SIZE + 1] = {0}, str2[STR_MAX_SIZE + 1] = {0};
    int z_res[2 * STR_MAX_SIZE] = {0};
    int max[2] = {0};
    int res = 0;
    res = scanf("%s",str1);
    res +=scanf("%s", str2);
    if (res == 2)
    {
        max[0] = max_suffix(str1, str2);
        max[1] = max_suffix(str2, str1);
    }
    printf("%d %d\n", max[0], max[1]);

    return 0;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
void zFunction2(char *s, int *z)
{
    int n = strlen(s);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int max_suffix(char *str1, char *str2)
{
    char str_cat[2 * STR_MAX_SIZE + 2] = {0};
    int z_res[2 * STR_MAX_SIZE] = {0};
    int max = 0;

    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int size_cat = size1 + size2 + 1;

    sprintf(str_cat, "%s#%s", str1, str2);
    zFunction2(str_cat, z_res);

    for (int i = size1 + 1; i < size_cat; i++)
        if (z_res[i] > max && z_res[i] == size_cat - i)
            max = z_res[i];
    return max;
}