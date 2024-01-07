#include <iostream>
using namespace std;

class my_distance
{
    int inch, feet;

public:
    my_distance(int i, int f)
    {
        inch = i;
        feet = f;
    }
    void operator-()
    {
        feet += 1;
        inch += 1;
        cout << "\n"
             << inch << " " << feet;
    }
};

int main()
{
    my_distance d1(5, 6);
    -d1;
    return 0;
}
