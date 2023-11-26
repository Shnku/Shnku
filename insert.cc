#include<iostream>
using namespace std;
class insertion
{
  public:
  int a[10],
  n,
  i,
  temp;
  void input(void) {
    cout<<"enter the no of array elements 'n': ";
    cin>>n;
    cout<<"enter the array elements: ";
    for(i = 0; i < n; i++) {
      cin>>a[i];
    }
  }
  void sort(void) {
    for(i = 1; i < n; i++) {
      if(a[i] > a[i+1]) {
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
  }
  void display(void) {
    cout<<"the sorted array is: ";
    for(i = 0; i < n; i++) {
      cout<<a[i];
    }
  }
};
int main() {
  insertion a;
  a.input();
  a.sort();
  a.display();
  return 0;
}