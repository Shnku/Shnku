#include <iostream>
using namespace std;
class B;
class A
{
    int x;

public:
    void setx(int);
    int getx();
    friend int sum(A, B);
};

class B
{
    int y;

public:
    void sety(int);
    int gety();
    friend int sum(A, B);
};

void A::setx(int x)
{
    this->x = x;
}
void B::sety(int y)
{
    this->y = y;
}
int A::getx()
{
    return x;
}
int B::gety()
{
    return y;
}

int sum(A oba, B obb)
{
    // return (oba.x + obb.gety()); //? if fsum is not a friend of b;
    return oba.x + obb.y;
}

int main()
{
    A v1;
    B v2;
    v1.setx(100);
    v2.sety(387);
    cout << "sum is: " << sum(v1, v2);
    cout << "sum2: " << v1.getx() + v2.gety();
    return 0;
}
