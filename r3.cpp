#include<iostream>
using namespace std;

int exp(int base,int power)
{
  if(power==0)
  {
    return 1;
  }
  if(power==1)
  {
    return base;
  }
  int ans=exp(base,power/2);
  if(power%2==0)
  {
    return ans*ans;
  }
  return base*ans*ans;
}

int main()
{
  int a,b;
  cin>>a;
  cin>>b;

   cout<<endl;
    cout<<exp(a,b);

return 0;
}
