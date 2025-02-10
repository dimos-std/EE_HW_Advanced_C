#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 5
#define END '.'
#define SEPARATOP ' '

void push(int data);
int pop(void);
void operate(char c);
int is_operator(char);
int is_digit(char);

int st[MAX_STACK_SIZE];
int pst = 0;

int main(void)
{
    int ret;
    char operator= 0,
         ch = 0;
    int number = 0;

    while ((ch = getchar()) != END)
    {
        if (is_digit(ch))
        {
            number += ch - '0';
            while ((ch = getchar()) != SEPARATOP)
            {
                number *= 10;
                number += ch - '0';
            }
            push(number);
            number = 0;
        }
        else if (is_operator(ch))
        {
            operate(ch);
        }
    }
    printf("%d\n", pop());
    return 0;
}
void push(int data)
{
    if (pst >= MAX_STACK_SIZE)
    {
        fprintf(stderr, "Error. Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    st[pst++] = data;
}
int pop()
{
    if (pst < 0)
    {
        fprintf(stderr, "Error. Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return st[--pst];
}

void operate(char c)
{
    if (pst > 1)
    {
        int arg1 = pop(), arg2 = pop();
        switch (c)
        {
        case '+':
            push(arg1 + arg2);
            break;
        case '-':
            push(arg2 - arg1);
            break;
        case '*':
            push(arg1 * arg2);
            break;
        case '/':
            if (arg1 != 0)
                push(arg2 / arg1);
            break;
        default:
            break;
        }
    }
}
int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}
int is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}
