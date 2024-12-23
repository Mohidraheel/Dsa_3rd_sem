#include <iostream>
using namespace std;
class minheap
{
    int *heap;
    int size;
    int count;

public:
    minheap(int s)
    {
        size = s;
        heap = new int[size];
        count = 0;
        heap[count] = -1;
    }

    void heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int min = i;
        if (left <= count && heap[left] < heap[min])
            min = left;
        if (right <= count && heap[right] < heap[min])
            min = right;
        if (min != i)
        {
            swap(heap[i], heap[min]);
            heapify(min);
        }
    }

    void buildmaxheap(int arr[], int n)
    {
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            heap[i] = arr[j];
            j++;
            count++;
        }
        size = n;
        for (int i = size / 2; i >= 1; i--)
        {
            heapify(i);
        }
    }
    void deletion()
    {
        if(count==0)
        {
            cout<<"Heap is empty";
            return;
        }
        heap[1]=heap[count];
        count--;
        heapify(1);

    }
    void display()
    {
        for(int i=1;i<=count;i++)
        {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }

    void insert(int val)
    {
        if(count==size)
        {
            cout<<"Heap is full";
            return;
        }
        count++;
        int i=count;
        heap[i]=val;
        while(i > 1 && heap[i] < heap[i/2])
        {
            swap(heap[i],heap[i/2]);
            i=i/2;
        }
    }
    void sorting()
    {
        int temp=count;
        while(count > 1)
        {
            swap(heap[1],heap[count]);
            count--;
            heapify(1);
        }
        count=temp;
        cout<<"Sorted array in descending order: ";
        for(int i=1;i<=count;i++)
        {
            cout<<heap[i]<<" ";
    
        }
    }

};
int main()
{
    minheap heap(10);
    heap.insert(50);
    heap.insert(45);
    heap.insert(315);
    heap.insert(35);
    heap.insert(5);
    heap.insert(789);
    heap.insert(0);
    heap.insert(7);
    heap.display();
    heap.sorting();
    return 0;
}
