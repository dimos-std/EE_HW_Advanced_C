// отсортировать слова
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END_STR_INPUT '.'
#define SEPARATOR ' '
#define END_INPUT '\n'
#define MAX_WORD_SIZE 20
typedef struct list
{
    char word[MAX_WORD_SIZE];
    struct list *next;
} list;

void add_to_list(list **, char *);
void swap_elements(list *, list *);
void print_list(list *);
void delete_list(list **);
void sort_list(list *);

int main(void)
{
    list *head = NULL;
    char word[MAX_WORD_SIZE];
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != END_INPUT && cnt < MAX_WORD_SIZE - 1)
    {
        if (ch == END_STR_INPUT || ch == SEPARATOR)
        {
            word[cnt] = '\0';
            add_to_list(&head, word);
            cnt = 0;
            if (ch == END_STR_INPUT)
                break;
        }
        else
        {
            word[cnt++] = ch;
        }
    }

    sort_list(head);
    print_list(head);
    delete_list(&head);

    return 0;
}
void print_list(list *head)
{
    list *cur = head;
    while (cur)
    {
        printf("%s ", cur->word);
        cur = cur->next;
    }
    putchar('\n');
}
void add_to_list(list **head, char *value)
{
    list *new = calloc(1, sizeof(list));
    strncpy(new->word, value, strlen(value));
    new->next = *head;
    *head = new;
}
void delete_list(list **head)
{
    list *cur, *next;
    if (head && *head)
    {
        cur = *head;
        while (cur)
        {
            next = cur->next;
            free(cur);
            cur = next;
        }
        *head = NULL;
    }
}
void swap_elements(list *a, list *b)
{
    if (a && b)
    {
        char tmp[MAX_WORD_SIZE] = {0};
        strncpy(tmp, a->word, MAX_WORD_SIZE);
        strncpy(a->word, b->word, MAX_WORD_SIZE);
        strncpy(b->word, tmp, MAX_WORD_SIZE);
    }
}
void sort_list(list *head)
{
    if (head)
    {
        for (list *cur = head; cur->next; cur = cur->next)
        {
            list *min = cur;
            for (list *next = cur->next; next; next = next->next)
            {
                if (strncmp(min->word, next->word, 20) > 0)
                    min = next;
            }
            if (cur != min)
                swap_elements(cur, min);
        }
    }
}
