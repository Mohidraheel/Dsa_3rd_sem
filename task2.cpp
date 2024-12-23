#include <iostream>
#include <string>

using namespace std;

class Maxheap
{

    int *heap;
    int capacity;
    int currentSize;

public:
    Maxheap() {}
    Maxheap(int cap)
    {
        capacity = cap;
        heap = new int[capacity];
        currentSize = 0;
        heap[currentSize] = -1;
    }

    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= currentSize && heap[left] > heap[largest])
            largest = left;

        if (right <= currentSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void insert(int val)
    {
        if (currentSize == capacity)
        {
            cout << "HAEP IS FULL !" << endl;
            return;
        }

        currentSize++;
        int i = currentSize;
        heap[i] = val;

        while (i > 1 && heap[i / 2] < heap[i])
        {
            swap(heap[i / 2], heap[i]);
            i = i / 2;
        }
    }

    void delete_heap()
    {
        if (isEmpty())
        {
            cout << "HEAP IS EMPTY ! " << endl;
            return;
        }

        heap[1] = heap[currentSize];
        currentSize--;

        heapify(1);
    }

    void print_heap()
    {
        if (isEmpty())
        {
            cout << "HEAP IS EMPTY ! " << endl;
            return;
        }

        for (int i = 1; i <= currentSize; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }
    void sorting()
    {
        int temp=currentSize;
        while(currentSize > 1)
        {
            swap(heap[1],heap[currentSize]);
            currentSize--;
            heapify(1);
        }
        currentSize=temp;
        for(int i=1;i<=currentSize;i++)
        {
            cout<<heap[i]<<" ";
        }

    }
    void builtheap(int arr[],int n)
    {
        int j=0;
        currentSize=0;
        for (int i = 1; i < n; i++)
        {
            heap[i]=arr[j];
            j++;
            currentSize++;

        }
        capacity=n;
        for(int i=currentSize/2;i>=1;i--)
        {
            heapify(i);
        }
    }
};

int main()
{
    Maxheap heap(20);
    heap.insert(50);
    heap.insert(45);
    heap.insert(315);
    heap.insert(35);
    heap.insert(5);
    heap.insert(789);
    // initial heap
    cout<<"INITAILA HEAP "<<endl;
    heap.print_heap();
    heap.sorting();
    cout<<endl;
    // delete root node from tea
    cout<<"HEAP AFTER DEELETION "<<endl;
    heap.delete_heap();
    // updated heap
    heap.print_heap();

    return 0;
}