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
    int no_of_node, data;
    root = NULL;
    no_of_node = get_input("no of nodes");
    if (root == NULL)
    {
        data = get_input("node data");
        root = (TREE *)calloc(1, sizeof(TREE));
        root->val = data;
        root->left = root->right = NULL;
    }
    for (int i = 1; i < no_of_node; i++)
    {
        data = get_input("node data");
        root = addnode(root, data);
    }
    return root;
}

TREE *addnode(TREE *root, int val)
{
    TREE *cur_pt, *pre_pt;
    TREE *temp = (TREE *)calloc(1, sizeof(TREE));
    temp->right = temp->right = NULL;
    temp->val = val;
    cur_pt = root;
    while (cur_pt != NULL)
    {
        pre_pt = cur_pt;
        cur_pt = (cur_pt->val < val) ? cur_pt->left : cur_pt->right;
    }
    if (pre_pt->val < val)
        pre_pt->left = temp;
    else
        pre_pt->right = temp;
    return root;
}

void inorder(TREE *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d", root->val);
    inorder(root->right);
}

void preorder(TREE *root)
{
    if (root == NULL)
        return;
    printf(" %d", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TREE *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->val);
}

void display(TREE *root)
{
    if (!root)
        return;
    display(root->left);
    printf("%d ");
}

int main()
{
    TREE *bst = NULL;
    int choice, data;
    printf("\n-------BST System--------\n");
    printf("\n1. create....");
    printf("\n2. add new node....");
    printf("\n3. display....");
    printf("\n4. inorder traversal....");
    printf("\n5. preorder traversal....");
    printf("\n6. postorder traversal....");
    printf("\n7. free tree....");
    printf("\nother option will quit......1");
    while (true)
    {
        choice = get_input("choice");
        switch (choice)
        {
        case 1:
            bst = create_bst(bst);
            break;
        case 2:
            data = get_input("node valu");
            bst = addnode(bst, data);
            break;
        case 3:
            break;
        case 4:
            inorder(bst);
            break;
        case 5:
            preorder(bst);
            break;
        case 6:
            postorder(bst);
            break;
        default:
            printf("exiting.......1");
            exit(0);
            break;
        }
    }
    return 0;
}
