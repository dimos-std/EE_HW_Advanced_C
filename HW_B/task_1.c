// #include <stdio.h>

// typedef struct list
// {
//     void *address;
//     size_t size;
//     char comment[64];
//     struct list *next;
// } list;

size_t totalMemoryUsage(list *head)
{
    list *p;
    size_t sum = 0;
    for (p = head; p; p = p->next)
        sum += p->size;
    
    return sum;
}
