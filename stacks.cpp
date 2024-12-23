#include<iostream>
using namespace std;

class stack
{
  int *arr;
  int size;
  int top;
  public:
  stack(int size)
  {
    this->size=size;
    top=-1;
    arr=new int[size];
  }

  void push(int data)
  {
    if(!isfull())
    {
      top++;
      arr[top]=data;
    }
    else
    {
      
      resize();
      top++;
      arr[top]=data;

    }
  }
  bool isfull()
  {
    if(top == size -1)
    {
      return true;
    }
    return false;
  }
  bool isempty()
  {
    if(top == -1)
    {
      return true;
    }
    return false;
  }
  void resize()
  {
    int *temp=new int[size];
    for(int i=0;i<size;i++)
    {
      temp[i]=arr[i];
    }
    delete []arr;
    size++;
    arr=new int[size];
    for(int i=0;i<size;i++)
    {
      arr[i]=temp[i];
    }
    delete []temp;
  }

  int peek()
  {
    if(!isempty())
    {
      return arr[top];
    }
  }
  void pop()
  {
    if(!isempty())
    {
      int x=peek();
      top--;
      cout<<x<<endl;
    }
  }
};
int main()
{
  stack s1(10);
  s1.push(5);
  s1.push(6);
  s1.push(4);
  s1.pop();
  int x=s1.peek();
  cout<<x<<endl;
  
return 0;
}
