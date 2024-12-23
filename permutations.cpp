#include<iostream>
using namespace std;

void swap(char &a ,char &b)
{
  char temp=a;
  a=b;
  b=temp;
}

void permute(string h,int left,int right)
{
  if(left==right)
  {
     cout << h << endl;
  }
  else
  {
    for(int i=left; i<=right ;i++)
    {
      swap(h[left],h[i]);
      permute(h,left+1,right);
      swap(h[left],h[i]);
    }

  }

}
int main()
{
  string hello;
  cout<<"Enter a string:";
  cin>>hello;

  permute(hello,0,hello.length()-1);
return 0;
}
