#include <iostream>
using namespace std;

int main()
{
  const int n = 0;
  int arr[n];
  cout << "en the value of n: ";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "en the" << i << "th term to array: ";
    cin >> arr[i];
  }
}
