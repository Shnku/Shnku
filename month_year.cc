#include <iostream>
using namespace std;
class Year
{
    int year, month, days;

public:
    void get(void);
    Year operator+(Year a);
    Year operator-(Year a);
    void show();
};

void Year::get()
{
    cout << "enter the year ,month ,days";
    cin >> year >> month >> days;
}

Year Year::operator+(Year a)
{
    Year t;
    t.days = days + a.days;
    t.year = year + a.year;
    t.month = month + a.month;
    if (t.days >= 30)
    {
        t.month = month + a.month + (t.days / 30);
        t.days = t.days % 30;
    }
    if (t.month >= 12)
    {
        t.year = year + a.year + (t.month / 12);
        t.month = t.month % 12;
    }
    cout << "the value after adition is" << t.year << ":" << t.month << ":" << t.days << endl;
    return t;
}

Year Year::operator-(Year a)
{
    Year t;
    t.days = days - a.days;
    t.year = year - a.year;
    t.month = month - a.month;
    if (t.days >= 30)
    {
        t.month = month - a.month - (t.days / 30);
        t.days = t.days % 30;
    }
    if (t.month >= 12)
    {
        t.year = year - a.year - (t.month / 12);
        t.month = t.month % 12;
    }

    cout << "the values after substraction is" << t.year << ":" << t.month << ":" << t.days << endl;
    return t;
}

void Year::show()
{
    cout << "\n"
         << year << "," << month << "," << days;
}

int main()
{
    Year x, y, z;
    int choice;
    cout << "enter your choice for add press 1\nand for substraction press 2:=" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        x.get();
        y.get();
        z = x + y;
        x.show();
        y.show();
        z.show();
        break;

    case 2:
        x.get();
        y.get();
        z = x - y;
        x.show();
        y.show();
        z.show();
        break;

    default:
        cout << "invalid choice" << endl;
        break;
    }
    return 0;
}
