#include<iostream>
using namespace std;

  int factorial=1;
int fac(int n)
{
  if(n==0)
  {
    return 1;
  }

  if(n<2)
  {
    return factorial;
  }
    factorial*=n;
    fac(n-1);
}
int main()
{
  int n=fac(5);
  cout<<n;

return 0;
}
