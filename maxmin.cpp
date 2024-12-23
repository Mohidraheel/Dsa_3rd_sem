#include <iostream>
using namespace std;
class minheap
{
  int arr[100];
  int capacity;

public:
  minheap()
  {
    this->capacity = 0;
    arr[0] = -1;
  }
  void heapify(int i)
  {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < capacity && arr[left] < arr[smallest])
    {
      smallest = left;
    }
    if (right < capacity && arr[right] < arr[smallest])
    {
      smallest = right;
    }
    if (smallest != i)
    {
      swap(arr[i], arr[smallest]);
      heapify(smallest);
    }
  }
  void insert(int val)
  {
    if (capacity == 100)
    {
      cout << "Heap is full. Cannot insert " << val << endl;
      return;
    }
    capacity++;
    int i = capacity;
    arr[i] = val;
    while (i > 1)
    {
      int parent = i / 2;
      if (arr[parent] > arr[i])
      {
        swap(arr[parent], arr[i]);
        i = parent;
      }
      else
      {
        break;
      }
    }
  }

  void deletion()
  {
    if (capacity == 0)
    {
      cout << "Heap is empty. Cannot delete" << endl;
      return;
    }
    arr[1] = arr[capacity];
    capacity--;
    heapify(1);
  }

  void print()
  {
    for (int i = 1; i <= capacity; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  void sort()
  {
    int temp = capacity;
    while (capacity > 1)
    {
      swap(arr[1], arr[capacity]);
      capacity--;
      heapify(1);
    }
    capacity = temp;

    
    for (int i = 1; i <= capacity; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};


void heapify(int arr[], int n, int i)
{
  int smallest = i;
  int left = 2 * i;
  int right = 2 * i + 1;
  if (left < n && arr[left] < arr[smallest])
  {
    smallest = left;
  }
  if (right < n && arr[right] < arr[smallest])
  {
    smallest = right;
  }
  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);
    heapify(arr, n, smallest);
  }
}

void buildHeap(int arr[], int n)
{
  for (int i = n / 2; i >= 1; i--)
  {
    heapify(arr, n, i);
  }
}

void sorting(int arr[], int n)
{
  int temp=n;
  while(n>=1)
  {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr, n, 1);
  }
  swap(arr[1],arr[2]);
  n=temp;
  for(int i=1;i<=n;i++)
  {
    cout<<arr[i]<<" ";
  }
}
int main()
{
  minheap h;
  h.insert(5);
  h.insert(2);
  h.insert(8);
  h.insert(1);
  h.insert(7);
  h.print();
  h.sort();
  cout << endl;
  h.deletion();
  h.print();
  int arr[6] = {-1, 2, 8, 1, 7, 9};
  buildHeap(arr, 5);
  for (int i = 1; i <= 5; i++)
  {
    cout << arr[i] << " ";
  }
  cout<<endl;
  sorting(arr, 5);

  return 0;
}
