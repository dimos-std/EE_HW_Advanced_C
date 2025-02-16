// вывести дерево "вид сверху"
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct tree
{
    datatype key;
    struct tree *left, *right;
} tree;
void insert(tree **, datatype);
void print_left_side(tree *);
void print_right_side(tree *);
void btUpView(tree *);

int main(void)
{
    tree *tr = NULL;
    int key = 0;

    scanf("%d", &key);
    while (key)
    {
        insert(&tr, key);
        scanf("%d", &key);
    }
    btUpView(tr);
    return 0;
}

void insert(tree **p, datatype key)
{
    if (*p == NULL)
    {
        *p = calloc(1, sizeof(struct tree));
        (*p)->key = key;
    }
    else if (key < (*p)->key)
    {
        insert(&((*p)->left), key);
    }
    else if (key > (*p)->key)
    {
        insert(&((*p)->right), key);
    }
}

void btUpView(tree *p)
{
    if (p)
    {
        print_left_side(p);
        print_right_side(p->right);
    }
    putchar('\n');
}
void print_left_side(tree *p)
{
    if (p)
    {
        print_left_side(p->left);
        printf("%d ", p->key);
    }
}
void print_right_side(tree *p)
{
    if (p)
    {
        printf("%d ", p->key);
        print_right_side(p->right);
    }
}