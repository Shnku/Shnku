#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp;

void insert()
{
    int val;
    cout << "enter the value of the data: ";
    cin >> val;
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = val;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = val;
        temp->next = NULL;
        rear = temp;
    }
}

void delet()
{
    temp = front;
    if (front == NULL)
    {
        cout << "queue underflow: ";
        return;
    }
    else
    {
        if (temp->next != NULL)
        {
            temp = temp->next;
            cout << "the deleted element of queue is: " << front->data << " ";
            free(front);
            front = temp;
        }
        else
        {
            cout << "the deleted item is: " << front->data;
            free(front);
            front = NULL;
            rear = NULL;
        }
    }
}

void display()
{
    temp = front;
    if ((front == NULL) && (rear == NULL))
    {
        cout << "No data is presented in the queue " << endl;
        return;
    }
    cout << "the queue elements are: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int ch;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of queue" << endl;
    cout << "4) Exit" << endl;
    // do{
    while (true)
    {
        cout << "\nen yer choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delet();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exit";
            exit(1);
            break;
        default:
            cout << "invalid choice" << endl;
            break;
        }
    }
    // } while (ch != 4);
    return 0;
}
