#include <iostream>
#define MAX 10
using namespace std;

class spars_node
{
    // public:
    int row, col, data;
    friend class sp_matrix; // or make public..
};

class sp_matrix
{
    int size;
    spars_node array[MAX];

public:
    sp_matrix() { size = 0; } // default constructor...
    void insrt_node(int, int, int);
    sp_matrix smat_addition(sp_matrix B);
    void display();
    ~sp_matrix() {} // default destructor...
};

void sp_matrix::insrt_node(int row, int col, int data)
{
    array[size].row = row;
    array[size].col = col;
    array[size].data = data;
    size++;
}

sp_matrix sp_matrix::smat_addition(sp_matrix m2)
{
    sp_matrix sum;
    int i = 0;
    while (i < size && i < m2.size)
    {
        if (array[i].row == m2.array[i].row)
        {
            if (array[i].col == m2.array[i].col)
            {
                sum.insrt_node(array[i].row, array[i].col, array[i].data + m2.array[i].data);
            }
            else if (array[i].col < m2.array[i].col)
            {
                sum.insrt_node(array[i].row, array[i].col, array[i].data);
                sum.insrt_node(m2.array[i].row, m2.array[i].col, m2.array[i].data);
            }
            else
            {
                sum.insrt_node(m2.array[i].row, m2.array[i].col, m2.array[i].data);
                sum.insrt_node(array[i].row, array[i].col, array[i].data);
            }
        }
        else if (array[i].row < m2.array[i].row)
        {
            sum.insrt_node(array[i].row, array[i].col, array[i].data);
            sum.insrt_node(m2.array[i].row, m2.array[i].col, m2.array[i].data);
        }
        else
        {
            sum.insrt_node(m2.array[i].row, m2.array[i].col, m2.array[i].data);
            sum.insrt_node(array[i].row, array[i].col, array[i].data);
        }
        i++;
    }
    while (i < size)
    {
        sum.insrt_node(array[i].row, array[i].col, array[i].data);
        i++;
    }
    while (i < m2.size)
    {
        sum.insrt_node(m2.array[i].row, m2.array[i].col, m2.array[i].data);
        i++;
    }
    return sum;
}

void sp_matrix::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i].row << " " << array[i].col << " " << array[i].data << endl;
    }
    cout << endl;
}

int main()
{
    sp_matrix A, B, C;
    A.insrt_node(0, 2, 30);
    A.insrt_node(1, 2, 44);
    A.insrt_node(2, 3, 59);

    B.insrt_node(0, 3, 22);
    B.insrt_node(1, 2, 33);
    B.insrt_node(3, 3, 67);
    B.insrt_node(4, 2, 66);

    A.display();
    B.display();

    C = A.smat_addition(B);
    C.display();
    return 0;
}

/*
0 2 30
1 2 44
2 3 59

0 3 22
1 2 33
3 3 67
4 2 66

0 2 30
0 3 22
1 2 77
2 3 59
3 3 67
4 2 66
*/
