#include <iostream>
using namespace std;

template <class T>
class matrix
{
    T **m;
    int row, col;

public:
    matrix(int a, int b)
    {
        row = a;
        col = b;

        // Allocate memory dynamically for the matrix
        m = new T *[row];
        for (int i = 0; i < row; i++)
            m[i] = new T[col];
    }

    // Destructor to free memory
    ~matrix()
    {
        for (int i = 0; i < row; i++)
            delete[] m[i];
        // delete[] m;
    }

    void getdata();
    void display();
    matrix mul(matrix);
};

template <class T>
void matrix<T>::getdata()
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> m[i][j];
}

template <class T>
void matrix<T>::display()
{
    for (int i = 0; i < row; i++)
    {
        cout << "\n";
        for (int j = 0; j < col; j++)
            cout << "\t" << m[i][j];
    }
}

template <class T>
matrix<T> matrix<T>::mul(matrix<T> B)
{
    matrix<T> C(row, B.col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < B.col; j++)
        {
            C.m[i][j] = 0;
            for (int k = 0; k < col; k++)
            {
                C.m[i][j] = C.m[i][j] + (m[i][k] * B.m[k][j]);
            }
        }
    }
    return C;
}

int main()
{
    matrix<int> A(2, 3), B(3, 2), C(2, 2);

    cout << "\nEnter matrix1 Elements";
    A.getdata();
    cout << "\nEnter matrix2 Elements";
    B.getdata();

    cout << "\nMatrix1 is: \n";
    A.display();

    cout << "\nMatrix2 is: \n";
    B.display();

    C = A.mul(B);
    cout << "\nMultiplication of the matrices is: \n";
    C.display();
}

/*
output..
Matrix1 is:

        1       2       3
        5       6       4
Matrix2 is:

        3       2
        4       8
        9       2
Multiplication of the matrices is:

        0       0
free(): double free detected in tcache 2
fish: “"/workspaces/Shnku/"matrix_dyna…” terminated by signal SIGABRT (Abort)
*/
