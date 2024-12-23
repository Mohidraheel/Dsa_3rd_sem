#include<iostream>
using namespace std;

class stack
{
  int arr[10];
  int top;
  public:
  stack()
  {
    top=-1;
  }
  void push(int data)
  {
    if(top<10-1)
    {
      top++;
      arr[top]=data;
    }
    else
    {
      cout<<"Stack Overflow"<<endl;
    }
  }
  void pop()
  {
    if(!isempty())
    {
      top--;
    }
  }
  bool isempty()
  {
    if(top==-1)
    {
      return true;
    }
    return false;
  }
  int peek()
  {
    if(!isempty())
    {
      return arr[top];
    }

  }
};

void primefactors(int n,stack &s)
{
  while(n%2==0)
  {
    cout<<"2"<<endl;
    s.push(2);
    n=n/2;
  }

  for(int i=3;i<n;i++)
  {
    while(n%i==0)
    {
      cout<<i<<endl;
      s.push(i);
      n=n/i;
    }
    
  }
  if(n>2)
  {
    cout<<n<<endl;
    s.push(n);
  }
}

int main()
{
  int n;
  cout<<"Enter A number:";
  cin>>n;
  stack ss;
  primefactors(n,ss);
  while(!ss.isempty())
  {
    cout<<ss.peek()<<" ";
    ss.pop();
  }
return 0;
}
