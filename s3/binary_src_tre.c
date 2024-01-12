#include <cstddef>
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
    printf("\nenter the %s: ", s);
    scanf("%d", &n);
    return n;
}

TREE *addnode(TREE *root, int val);
TREE *create_bst(TREE *root)
{
    TREE *temp;
    int no_of_node, val;
    no_of_node = get_input("no of nodes");
    for (int i = 0; i < no_of_node; i++)
    {
        val = get_input("node data");
        temp = addnode(root, val)
    }
    return root;
}

TREE *addnode(TREE *root, int val)
{
    TREE *cur_pt, *pre_pt;
    TREE *temp = (TREE *)calloc(1, sizeof(TREE));
    temp->val = val;
    temp->right = temp->right = NULL;
    while (!cur_pt)
    {
        pre_pt = cur_pt;
        if (cur_pt->val > val)
            cur_pt = cur_pt->right;
        else
            cur_pt = cur_pt->left;
    }
    if (pre_pt->val < val)
        pre_pt->left = temp;
    else
        pre_pt->right = temp;
    return root;
}

void display(TREE *root){
    
}

int main()
{
    int choice, v;
    TREE *root = NULL;
    printf("_____this is A BST system___");
    printf("\n1)create...");
    printf("\n2)add node...");
    printf("\n3)display...");
    while (true)
    {
        choice = get_input("choice");
        switch (choice)
        {
        case 1:
            root = create_bst(root);
            printf("__bst created___");
            break;
        case 2:
            printf("__adding node___");
            v = get_input("node value");
            root = addnode(root, v);
            break;
        case 3:
            printf("__displaying tree___\n");
            break;
        }
    }
    return 0;
}
