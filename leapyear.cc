#include <iostream>
using namespace std;

void check (int year)
{
  int key = (year - (4 * (year / 4)) == 0) && (year - (100 * (year / 100)) != 0) || (year - (400 * (year / 400)) == 0);
  cout << (key == 1 ? "leapyear" : "not");
}

int main ()
{
  int y[4] = { 2004, 1900, 1975, 2016 };
//   cout << "en the year: ";
//   cin >> year;
    


  return 0;
}
