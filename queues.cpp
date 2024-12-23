#include<iostream>
using namespace std;

class linearqueue
{
  int *arr;
  int size;
  int rear;
  int front;
  public:
  linearqueue(int s)
  {
    size=s;
    arr=new int[s];
    rear=-1;
    front=-1;
  }
  bool isfull()
  {
    if(rear==size -1)
    {
      return true;
    }
    return false;
  }
  bool isempty()
  {
    if(-1==front)
    {
      return true;
    }
    return false;
  }

  void enqueue(int data)
  {
    if(isfull())
    {
      cout<<"Queue is Full"<<endl;
      return;
    }
    else
    {
      if(isempty())
      {
        front=0;
      }
      rear++;
      arr[rear]=data;
    }

  }

  void dequeue()
  {
    if(!isempty())
    {
      int x=arr[front];
      cout<<x<<endl;
      front++;
    }
  }

};

class circularqueue
{
  int *arr;
  int size;
  int front;
  int rear;
  int count;
  public:
  circularqueue(int s)
  {
    size=s;
    arr=new int[s];
    front=-1;
    rear=-1;
    count=0;
  }

  bool isfull()
  {
    if(count < size)
    {
      return false;
    }
    return true;
  }

  bool isempty()
  {
    if(count == 0)
    {
      return true;
    }
    return false;
  }

  void enqueue(int data)
  {
    if(!isfull())
    {
      rear=(rear + 1)%size;
      arr[rear]=data;
      count++;
    }
    else
    {
      cout<<"Queue is full "<<endl;
    }
  }

  void dequeue()
  {
    if(!isempty())
    {
      front=(front + 1)%size;
      int x=arr[front];
      cout<<"Dequeue:"<<x<<endl;
      count--;
    }
    else
    {
      cout<<"Queue is already Empty"<<endl;
    }
  }

  int peek()
  {
    if(!isempty())
    {
      front++;
      int x=arr[front];
      front--;
      return x;
    }
  }



};
int main()
{
  circularqueue q1(5);
  q1.enqueue(10);
  q1.dequeue();
  q1.enqueue(5);
  q1.enqueue(6);
  q1.enqueue(7);
  q1.enqueue(8);
  q1.enqueue(9);
  cout<<q1.peek()<<endl;
return 0;
}
