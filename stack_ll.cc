#include <iostream>
using namespace std;
struct node
{
    struct node *next;
    int data;
};

struct node *head = NULL;

class total
{
public:
    void pop();
    void display();
    void push();
};

int main()
{
    total a;
    int ch;
    while (1)
    {
        cout << "\nenter 1 for push\nand 2 for pop\n3 for quit :: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a.push();
            a.display();
            break;
        case 2:
            a.pop();
            a.display();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "\nenter the choice in between 1 and 2 and 3: " << endl;
            break;
        }
    }
    return 0;
}

//____________functions___________
void total::push()
{
    struct node *newnode = nullptr;
    int value;
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "enter the value to be pushed: ";
    cin >> value;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void total::pop()
{
    struct node *temp = head;
    if (head == NULL)
    {
        cout << "stack is empty" << endl;
        return;
    }
    head = head->next;
    cout << "the popped element is: " << temp->data << endl;
    free(temp);
}

void total::display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
