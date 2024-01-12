#include <stdio.h>
#include <stdlib.h>

typedef struct bisearchtree
{
    int val;
    struct bisearchtree *left;
    struct bisearchtree *right;
} TREE;

typedef enum
{
    false,
    true
} bool;

int get_input(char *s)
{
    int n;
    printf("enter the %s: ", s);
    scanf("%d", &n);
    return n;
}

TREE *create_bst(TREE *root)
{
    TREE *temp, *cur_pt, *pre_pt;
    temp = cur_pt = pre_pt = NULL;
    int no_of_node;
    no_of_node = get_input("no of nodes");
    for (int i = 0; i < no_of_node; i++)
    {
    }
}

TREE *addnode(TREE *root, int val)
{
    TREE *cur_pt, *pre_pt;
    TREE *temp = (TREE *)calloc(1, sizeof(TREE));
    val = get_input("node data");
    temp->val = val;
    temp->right = temp->right = NULL;
    
}

int main()
{
    int a = get_input("garbage vall");
    printf("a is== %d", a);
    return 0;
}
