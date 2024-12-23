#include<iostream>
using namespace std;


class stack
{
  int *arr;
  int size;
  int top2;
  int top1;
  public:
  stack(int s)
  {
    size=s;
    arr=new int[size];
    top1=-1;
    top2=size;
  }
  void push1(int data)
  {
    if(top2-top1>0)
    {
      arr[++top1]=data;
    }
  }

  void push2(int data)
  {
      if(top2-top1>0)
    {
      arr[--top2]=data;
    }

  }

  void pop1()
  {
    if(top1>=0)
    {
      top1--;
    }
  }

  void pop2()
  {
    if(top2<size)
    {
      top2++;
    }
  }
  int peek()
  {
    if(top1!=-1)
    {
      return arr[top1]; 
    }

  }

};
void solve(stack &s,int count,int size)
{
  if(count==size/2)
  {
    s.pop1();
    return;
  }

  int num=s.peek();
  s.pop1();

  solve(s,count++,size);
  s.push1(num);


}

void deleteatmiddle(stack &s,int count,int size)
{
  solve(s,count,size);

}
int main()
{
return 0;
}



