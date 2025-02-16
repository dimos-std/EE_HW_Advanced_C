// найти "брата" по ключу
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct tree
{
    datatype key;
    struct tree *left, *right;
    struct tree *parent;
} tree;
void insert(tree **, datatype, tree *);
tree *findBrother(tree *, int);

int main(void)
{
    tree *tr = NULL;
    tree *brother = NULL;
    int key = 0;
    int brother_key = 0;

    scanf("%d", &key);
    while (key)
    {
        insert(&tr, key, NULL);
        scanf("%d", &key);
    }
    scanf("%d", &key);
    if (key)
    {
        if ((brother = findBrother(tr, key)) != NULL)
            brother_key = brother->key;
        printf("%d\n", brother_key);
    }

    return 0;
}

void insert(tree **p, datatype key, tree *pr)
{
    if (*p == NULL)
    {
        *p = calloc(1, sizeof(struct tree));
        (*p)->key = key;
        (*p)->parent = pr;
    }
    else if (key < (*p)->key)
    {
        insert(&((*p)->left), key, *p);
    }
    else if (key > (*p)->key)
    {
        insert(&((*p)->right), key, *p);
    }
}

tree *findBrother(tree *root, int key)
{
    int find = 0;
    while (root)
    {
        if (root->key > key)
            root = root->left;
        else if (root->key < key)
            root = root->right;
        else
        {
            if (root->parent == NULL)
                return NULL;
            if (root->parent->left == root)
                return root->parent->right;
            else
                return root->parent->left;
        }
    }
    return NULL;
}

tree *search_tree(tree *root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    else if (root->key > key)
        return search_tree(root->left, key);
    else
        return search_tree(root->right, key);
}