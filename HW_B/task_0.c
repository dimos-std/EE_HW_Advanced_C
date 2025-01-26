// #include <inttypes.h>
// #include <stdio.h>

// typedef struct list
// {
//     uint64_t address;
//     size_t size;
//     char comment[64];
//     struct list *next;
// } list;

uint64_t findMaxBlock(list *head)
{
    list *p;
    size_t max_size = 0;
    uint64_t address = 0;
    for (p = head; p; p = p->next)
    {
        if (p->size > max_size)
        {
            max_size = p->size;
            address = p->address;
        }
    }
    return address;
}
