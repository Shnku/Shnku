#include <iostream>
using namespace std;

template <class T>
class matrix
{
    T m[10][10];
    int row, col;

public:
    matrix(int a, int b)
    {
        row = a;
        col = b;
    }
    void getdata();
    void display();
    matrix addition(matrix);
    matrix sub(matrix);
    matrix trans();
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
matrix<T> matrix<T>::addition(matrix<T> B)
{
    matrix<T> C(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            C.m[i][j] = m[i][j] + B.m[i][j];
    return C;
}

template <class T>
matrix<T> matrix<T>::sub(matrix<T> B)
{
    matrix<T> C(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            C.m[i][j] = m[i][j] - B.m[i][j];
    return C;
}

template <class T>
matrix<T> matrix<T>::trans()
{
    matrix<T> C(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            C.m[i][j] = m[j][i];
    return C;
}

template <class T>
matrix<T> matrix<T>::mul(matrix<T> B)
{
    matrix<T> C(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            C.m[i][j] = 0;
            for (int k = 0; k < row; k++)
            {
                C.m[i][j] = C.m[i][j] + (m[i][k] * B.m[k][j]);
            }
        }
    }
    return C;
}

int main()
{
    // int r, c;
    // cout << "\nEnter matrix Size(row&col): ";
    // cin >> r >> c;
    // cout << "\nInteger Matrix";
    // matrix<int> A(r, c), B(r, c), C(r, c);

    matrix<int> A(2, 3), B(3, 2), C(3, 3);

    cout << "\nEnter matrix1 Elements";
    A.getdata();
    cout << "\nEnter matrix2 Elements";
    B.getdata();
    cout << "\nMatrix1 is: \n";
    A.display();
    cout << "\nMatrix2 is: \n";
    B.display();
    C = A.addition(B);
    cout << "\nMatrix Addition is: \n";
    C.display();
    C = A.sub(B);
    cout << "\nMatrix subtraction is: \n";
    C.display();
    C = A.trans();
    cout << "\nMatrix transposition is: \n";
    C.display();
    C = A.mul(B);
    cout << "\nMatrix multiplication is: \n";
    C.display();
}

/*
output..
Enter matrix1 Elements1 2 3
4 5 6

Enter matrix2 Elements4 5 6
1 2 3

Matrix1 is:

        1       2       3
        4       5       6
Matrix2 is:

        4       5
        6       1
        2       3
Matrix Addition is:

        5       7       -303545389
        10      6       6
Matrix subtraction is:

        -3      -3      303545395
        -2      4       6
Matrix transposition is:

        1       4       0
        2       5       0
Matrix multiplication is:

        16      7       -303545392
        46      25      -1214181568⏎
*/
