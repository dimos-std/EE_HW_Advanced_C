// шифр Цезаря
#include <stdio.h>

#define END '.'
int main(void)
{
    int N;
    char ch;

    scanf("%d ", &N);
    if (N >= 0)
    {
        while ((ch = getchar()) != END)
        {
            if (ch >= 'a' && ch <= 'z')
                ch = 'a' + (ch - 'a' + N) % 26;
            else if (ch >= 'A' && ch <= 'Z')
                ch = 'A' + (ch - 'A' + N) % 26;
            putchar(ch);
        }
        putchar(END);
        putchar('\n');
    }
    return 0;
}