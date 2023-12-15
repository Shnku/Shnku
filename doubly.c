#include <stdio.h>
#include <stdlib.h>

typedef struct link_list {
    int data;
    struct link_list* p_prev;
    struct link_list* p_next;
} LIst;

void display(LIst* head);
void create_node(LIst** head);

void add_beg(LIst** head, int data);
void add_end(LIst** head, int data);
void add_after(LIst** head, int pos, int data);
void add_before(LIst** head, int pos, int data);

void delete_beg(LIst** head);
void delete_end(LIst** head);
void delete_after(LIst** head, int pos);
void delete_before(LIst** head, int pos);

int main() {
    int c, d, pos;
    LIst* head = NULL;
    while (1) {
        printf("\n\t\\link list menu options...\\");
        printf("\n\t(_1_) = for creating the list");
        printf("\n\t(_2_) = adding beginning of the list");
        printf("\n\t(_3_) = adding end of the list");
        printf("\n\t(_4_) = to display the list...");
        printf("\n\t(_5_) = adding after the node... ");
        printf("\n\t(_6_) = adding before the node...");
        printf("\n\t(_7_) = deleting beginning of list... ");
        printf("\n\t(_8_) = deleting end of list... ");
        printf("\n\t(_9_) = deleting after of node....");
        printf("\n\t(_10_) = deleting before of node....");
        printf("\n\t_________others to quit");

        printf("\n\n>>_ENTER YOUR CHOICE_<< --");
        scanf("%d", &c);
        switch (c) {
        case 1:
            printf("\n_______for creating the list_______\n");
            create_node(&head);
            break;
        case 2:
            printf("\n_______adding beginning of the list_______\n");
            printf("enter the list data: ");
            scanf("%d", &d);
            add_beg(&head, d);
            break;
        case 3:
            printf("\n_______adding end of the list_______\n");
            printf("enter the list data: ");
            scanf("%d", &d);
            add_end(&head, d);
            break;
        case 4:
            printf("\n_____________Display______________\n");
            display(head);
            break;
        case 5:
            printf("\n_______adding after of the node_______\n");
            printf("enter after what to add:  ");
            scanf("%d", &pos);
            printf("enter the list data: ");
            scanf("%d", &d);
            add_after(&head, pos, d);
            break;
        case 6:
            printf("\n_______adding before of the node_______\n");
            printf("enter before what to add:  ");
            scanf("%d", &pos);
            printf("enter the list data: ");
            scanf("%d", &d);
            add_before(&head, pos, d);
            break;
        case 7:
            printf("\n_______delete_beginning of list_______\n");
            delete_beg(&head);
            break;
        case 8:
            printf("\n_______delete_end of list_______\n");
            delete_end(&head);
            break;
        case 9:
            printf("\n_______delete_after of list_______\n");
            printf("\nenter after what: ");
            scanf("%d", &pos);
            delete_after(&head, pos);
            break;
        case 10:
            printf("\n_______delete_before of list_______\n");
            printf("\nenter after what: ");
            scanf("%d", &pos);
            delete_before(&head, pos);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

/*__________________end of main_____________________*/
/*______________creation function_____________________*/

void create_node(LIst** head) {
    int n, i, d;
    LIst* temp;
    LIst* ptr;
    printf("Enter the no of list items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        temp = (LIst*)calloc(1, sizeof(LIst));
        printf("enter the list data: ");
        scanf("%d", &d);
        temp->data = d;
        temp->p_next = NULL;
        if (*head == NULL) //replace with add_beg
            *head = temp;
        else {
            ptr = *head;
            while (ptr->p_next != NULL)
                ptr = ptr->p_next;
            ptr->p_next = temp; //replace with add_end
            temp->p_prev = ptr;
        }
    }
}

/*________________________addition function__________________________*/

void add_beg(LIst** head, int d) // aad begenning function..
{
    LIst* temp;
    temp = (LIst*)calloc(1, sizeof(LIst));
    temp->data = d;
    temp->p_next = *head;
    temp->p_prev = (*head)->p_prev;
    *head = temp;
}

void add_end(LIst** head, int d) // add end function...
{
    LIst* temp;
    LIst* ptr = *head;
    temp = (LIst*)calloc(1, sizeof(LIst));
    temp->data = d;
    temp->p_next = NULL;
    if (*head == NULL) {
        *head = temp;
        temp->p_prev = NULL;
        return;
    }
    while (ptr->p_next != NULL) {
        ptr = ptr->p_next;
    }
    ptr->p_next = temp;
    temp->p_prev = ptr;
}

void add_after(LIst** head, int after, int d) // add after any node..
{
    LIst *ptr, *temp;
    if (!(*head)) {
        printf("list is empty....\n");
        return;
    }
    ptr = *head;
    while (ptr != NULL) {
        if (ptr->data == after) {
            temp = (LIst*)calloc(1, sizeof(LIst));
            temp->data = d;
            temp->p_prev = ptr;
            temp->p_next = ptr->p_next; // if null then nul->next==null
            ptr->p_next = temp;
            return;
        }
        ptr = ptr->p_next;
    }
    printf("\nlement not found");
}

void add_before(LIst** head, int before, int d) // add before any node..
{
    LIst *ptr, *temp;
    if (*head == NULL) {
        printf("list is empty....");
        return;
    }
    if ((*head)->data == before) {
        temp = (LIst*)calloc(1, sizeof(LIst));
        temp->data = d;
        temp->p_prev = NULL;
        temp->p_next = *head;
        (*head)->p_prev = temp;
        *head = temp;
        return;
    }
    ptr = *head;
    while (ptr != NULL) {
        if (ptr->data == before) {
            temp = (LIst*)calloc(1, sizeof(LIst));
            temp->data = d;
            temp->p_prev = ptr->p_prev;
            ptr->p_prev = temp;
            temp->p_prev->p_next = temp;
            temp->p_next = ptr;
            // ptr->p_prev->p_next = temp; // problem here..
            return;
        }
        ptr = ptr->p_next;
    }
    printf("element doesnot exist\n");
}

/*__________________________delettiong______________________________*/

void delete_beg(LIst** head) // delete begenning of the node..
{
    LIst* ptr;
    if (!(*head)) {
        printf("list is empty....");
        return;
    }
    ptr = *head;
    (*head)->p_next->p_prev = NULL;
    *head = (*head)->p_next;
    free(ptr);
}

void delete_end(LIst** head) // delete end of the node..
{
    LIst *ptr, *temp;
    if (!(*head)) {
        printf("list is empty....");
        return;
    }
    if ((*head)->p_next == NULL) {
        temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    ptr = *head;
    while (ptr->p_next != NULL) {
        ptr = ptr->p_next;
    }
    temp = ptr;
    ptr->p_prev->p_next = NULL;
    free(temp);
}

void delete_after(LIst** head, int after) // delete after given node..
{
    LIst *ptr, *temp;
    if (!(*head)) {
        printf("list is empty....");
        return;
    }
    ptr = *head;
    while (ptr != NULL && ptr->data != after)
        ptr = ptr->p_next;
    if (ptr == NULL)
        printf("element not found\n");
    else if (ptr->p_next == NULL)
        printf("no node after this..\n");
    else {
        temp = ptr->p_next;
        ptr->p_next = temp->p_next; // ptr->p_next->p_next
        if (temp->p_next != NULL)
            temp->p_next->p_prev = ptr;
        free(temp);
    }
}

void delete_before(LIst** head, int before) // delete before specified node....
{
    LIst *ptr, *prev, *temp;
    if (!(*head)) {
        printf("list is empty....");
        return;
    }
    if ((*head)->data == before) {
        printf("\nno node to delete..only node");
        return;
    }
    ptr = *head;
    while (ptr->p_next != NULL && (ptr->p_next)->data != before) {
        prev = ptr;
        ptr = ptr->p_next;
    }
    if (ptr->p_next == NULL)
        printf("\n element not found..");
    else if (ptr->data == (*head)->data) {
        temp = *head;
        *head = (*head)->p_next;
        free(temp);
    } else {
        prev->p_next = ptr->p_next;
        free(ptr);
    }
}

/*_________________displayind code___________________________*/

void display(LIst* head) // displaying the list..
{
    if (head == NULL)
        printf("list is empty...");
    while (head != NULL) {
        printf("%d <=> ", head->data);
        head = head->p_next;
    }
    printf("\b\b\b ");
}
