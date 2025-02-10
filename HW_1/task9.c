// упковать массив

#include <stdio.h>
#include <inttypes.h>

struct pack_array
{
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int *arr, struct pack_array *pack)
{
    pack->array = pack->count0 = pack->count1 = 0;
    for (int i = 0; i < 32; i++)
    {
        pack->array |= (uint32_t)arr[i] << (31 - i);
        pack->count1 += arr[i];
    }
    pack->count0 = 32 - pack->count1;
}

int main(int argc, char **argv)
{
    int arr[32];
    struct pack_array pack;

    for (int i = 0; i < 32; i++)
        scanf("%d", &(arr[i]));
    array2struct(arr, &pack);
    printf("%" PRIu32 " %" PRIu32 " %" PRIu32 "\n", pack.array, pack.count0, pack.count1);
    return 0;
}