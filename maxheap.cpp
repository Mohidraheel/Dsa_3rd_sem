#include<iostream>
using namespace std;
class maxheap
{
  int arr[100];
  int count;
  public:
  maxheap()
  {
   
    count=0;
    arr[count]=-1;
  }

  void insert(int val)
  {
    if(count==100)
    {
      cout<<"Heap is full";
      return;
    }
    count++;
    int i=count;
    arr[i]=val;
    while(i > 1)
    {
      int parent=i/2;
      if(arr[parent] < arr[i] )
      {
        swap(arr[parent],arr[i]);
        i=parent;

      }
      else
      {
        break;
      }
    }

  }
  void heapfiy(int i)
  {
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left < count && arr[left] > arr[largest])
    {
      largest=left;
    }
    if(right < count && arr[right] > arr[largest])
    {
      largest=right;
    }
    if(largest!=i)
    {
      swap(arr[i],arr[largest]);
      heapfiy(largest);
    }
  }

  void deletion()
  {
    int max=arr[1];
    arr[1]=arr[count];
    count--;
    heapfiy(1);

  }

  void sort()
  {
    int temp=count;
    while(count > 1)
    {
      swap(arr[1],arr[count]);
      count--;
      heapfiy(1);

    }
    count=temp;
    for(int i=1;i<=count;i++)
    {
      cout<<arr[i]<<" ";
    }
  }

  void print()
  {
    for(int i=1;i<=count;i++)
    {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

};
int main()
{
  maxheap mh;
  mh.insert(5);
  mh.insert(3);
  mh.insert(2);
  mh.insert(1);
  mh.insert(9);
  mh.print();
  cout<<endl;
  mh.sort();
  mh.deletion();
  cout<<endl;
  mh.sort();
return 0;
}
