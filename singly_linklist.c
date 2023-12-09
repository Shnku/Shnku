#include <stdio.h>
#include <stdlib.h>

typedef struct link_list
{
    int data;
    struct link_list *next;
} LIst;

void display(LIst *head);
void create_node(LIst **first);
// int is_empty(LIst *head);

void add_beg(LIst **first);
void add_end(LIst **first);
void add_after(LIst **head);
void add_before(LIst **head);

void delete_beg(LIst **head);
void delete_end(LIst **head);
void delete_after(LIst **head);
void delete_before(LIst **head);

int main()
{
    int c;
    LIst *head = NULL;
    printf("\n\t\\link list menu options...\\");
    printf("\n\t(1) = for creating the list");
    printf("\n\t(2) = adding beginning of the list");
    printf("\n\t(3) = adding end of the list");
    printf("\n\t(4) = to display the list...");
    printf("\n\t(5) = adding after the node... ");
    printf("\n\t(6) = adding before the node...");
    printf("\n\t(7) = deleting beginning of list... ");
    printf("\n\t(8) = deleting end of list... ");
    printf("\n\t(9) = deleting after of node....");
    printf("\n\t(10) = deleting before of node....");
    printf("\n\t_____others to quit");

    while (1)
    {
        printf("\n\n>>ENTER YOUR CHOICE<< --");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("\n____for creating the list__\n");
            create_node(&head);
            break;
        case 2:
            printf("\n____adding beginning of the list__\n");
            add_beg(&head);
            break;
        case 3:
            printf("\n____adding end of the list__\n");
            add_end(&head);
            break;
        case 4:
            printf("\n______Display_____\n");
            display(head);
            break;
        case 5:
            printf("\n____adding after of the node__\n");
            add_after(&head);
            break;
        case 6:
            printf("\n____adding before of the node__\n");
            add_before(&head);
            break;
        case 7:
            printf("\n____delete_beginning of list__\n");
            delete_beg(&head);
            break;
        case 8:
            printf("\n____delete_end of list__\n");
            delete_end(&head);
            break;
        case 9:
            printf("\n____delete_after of list__\n");
            delete_after(&head);
            break;
        case 10:
            printf("\n____delete_before of list__\n");
            delete_before(&head);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
/*
/ _______end of main________ /
    / _____creation function________ /
*/

void create_node(LIst **first)
{
    int n, i, d;
    LIst *temp;
    LIst *ptr;
    printf("Enter the no of list items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        temp = (LIst *)malloc(sizeof(LIst));
        printf("enter the list data: ");
        scanf("%d", &d);
        temp->data = d;
        temp->next = NULL;
        if (*first == NULL)
            *first = temp;
        else
        {
            ptr = *first;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
}

/* _________addition function_________ */

void add_beg(LIst **first) // aad begenning function..
{
    LIst *temp;
    int d;
    temp = (LIst *)malloc(sizeof(LIst));
    printf("enter the list data: ");
    scanf("%d", &d);
    temp->data = d;
    temp->next = *first;
    *first = temp;
}

void add_end(LIst **first) // add end function...
{
    LIst *temp;
    LIst *ptr = *first;
    int d;
    temp = (LIst *)malloc(sizeof(LIst));
    printf("enter the list data: ");
    scanf("%d", &d);
    temp->data = d;
    temp->next = NULL;
    if (*first == NULL)
        *first = temp;
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void add_after(LIst **head) // add after any node..
{
    int after, d;
    LIst *ptr, *temp;
    if (!(*head))
    {
        printf("list is empty....\n");
        return;
    }
    printf("enter after what to add:  ");
    scanf("%d", &after);
    printf("enter the list data: ");
    scanf("%d", &d);

    ptr = *head;
    while (ptr != NULL && ptr->data != after)
        ptr = ptr->next;
    if (ptr == NULL)
        printf("\nlement not found");
    else
    {
        temp = (LIst *)malloc(sizeof(LIst));
        temp->data = d;
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void add_before(LIst **head) // add before any node..
{
    int before, d;
    LIst *ptr, *temp, *prev = NULL;
    if (!(*head))
    {
        printf("list is empty....");
        return;
    }
    printf("en before what to add:  ");
    scanf("%d", &before);
    printf("enter the list data: ");
    scanf("%d", &d);

    ptr = *head;
    temp = (LIst *)malloc(sizeof(LIst));
    temp->data = d;
    if ((*head)->data == before)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        while (ptr != NULL && ptr->data != before)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("element doesnot exist\n");
        else
        {
            temp->next = ptr;
            prev->next = temp;
        }
    }
}

/* _________delettiong___________ */

void delete_beg(LIst **head) // delete begenning of the node..
{
    LIst *ptr;
    if (!(*head))
    {
        printf("list is empty....");
        return;
    }
    ptr = *head;
    *head = (*head)->next;
    free(ptr);
}

void delete_end(LIst **head) // delete end of the node..
{
    LIst *ptr, *temp, *prev = NULL;
    if (!(*head))
    {
        printf("list is empty....");
        return;
    }
    if ((*head)->next == NULL)
    {
        temp = *head;
        free(temp);
        *head = NULL;
    }
    ptr = *head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = NULL;
    free(temp);
}

void delete_after(LIst **head) // delete after given node..
{
    int after;
    LIst *ptr, *temp;
    if (!(*head))
    {
        printf("list is empty....");
        return;
    }
    printf("\nenter after what: ");
    scanf("%d", &after);

    ptr = *head;
    while (ptr != NULL && ptr->data != after)
        ptr = ptr->next;
    if (ptr == NULL)
        printf("element not found\n");
    else if (ptr->next == NULL)
        printf("no node after this..\n");
    else
    {
        temp = ptr->next;
        ptr->next = temp->next; // ptr->next->next
        free(temp);
    }
}

void delete_before(LIst **head) // delete before specified node....
{
    int before;
    LIst *ptr, *prev, *temp;
    if (!(*head))
    {
        printf("list is empty....");
        return;
    }
    printf("\nenter before what : ");
    scanf("%d", &before);

    if ((*head)->data == before)
    {
        printf("\nno node to delete..only node");
        return;
    }
    ptr = *head;
    while (ptr->next != NULL && (ptr->next)->data != before)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
        printf("\n element not found..");
    else if (ptr->data == (*head)->data)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        prev->next = ptr->next;
        free(ptr);
    }
}

/*______displayind code__________ */

void display(LIst *head) // displaying the list..
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\b\b  ");
}

/*

        \link list menu options...\
        (1) = for creating the list
        (2) = adding beginning of the list
        (3) = adding end of the list
        (4) = to display the list...
        (5) = adding after the node...
        (6) = adding before the node...
        (7) = deleting beginning of list...
        (8) = deleting end of list...
        (9) = deleting after of node....
        (10) = deleting before of node....
        _____others to quit

>>ENTER YOUR CHOICE<< --1

____for creating the list__
Enter the no of list items: 4
enter the list data: 10
enter the list data: 20
enter the list data: 30
enter the list data: 40


>>ENTER YOUR CHOICE<< --4

______Display_____
10->20->30->40

>>ENTER YOUR CHOICE<< --12
*/
