#include <iostream>
#include <string>

using namespace std;

class Maxheap
{

    int *heap;
    int capacity;
    int currentSize;

public:
    Maxheap(){}
    Maxheap(int cap)
    {
        capacity = cap;
        heap = new int[capacity];
        currentSize = 0;
        heap[currentSize] = -1;
    }

   void heapify(int i) {
        int largest = i;
        int left = 2 * i ;
        int right = 2 * i + 1;

        if (left <= currentSize && heap[left] > heap[largest])
            largest = left;

        if (right <= currentSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
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

    void delete_heap(){
        if (isEmpty())
        {
            cout<<"HEAP IS EMPTY ! "<<endl;
            return;
        }

        heap[1]=heap[currentSize];
        currentSize--;
        
        heapify(1);
        
    }

    void print_heap(){
        if (isEmpty())
        {
            cout<<"HEAP IS EMPTY ! "<<endl;
            return;
        }


        for (int i = 1; i <= currentSize; i++)
        {
            cout<<heap[i]<<" ";
        }
        cout<<endl;
        
        
    }

    void buildheap(int arr[],int n){
        if (n>capacity)
        {
            cout<<"ARRAY SIZE EXCEEDS HEAP !"<<endl;
            return;
        }
        
        int j=0;
        for (int i = 1; i < n; i++)
        {
            heap[i]=arr[j];
            j++;
        }
        currentSize=n;
        for (int i =currentSize/2; i >=1; i--)
        {
            heapify(i);
        }
        
        
        
    }

    bool isEmpty() const {
        return currentSize==0;
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
    heap.print_heap();
    heap.delete_heap();
    heap.print_heap();

    int arr[]={2,3,5,1,8,9,3,5,2};
    int size=sizeof(arr)/sizeof(int);
    heap.buildheap(arr,size);
    heap.print_heap();


    return 0;
}