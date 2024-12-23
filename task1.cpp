#include <iostream>
#include <string>
using namespace std;

class Package
{
    string del_time;
    string importance; // high, medium, low
    int priority;

public:
    Package(string time, string import)
    {
        importance = import;
        del_time = time;

        if (importance == "high")
        {
            priority = 1;
        }
        else if (importance == "medium")
        {
            priority = 3;
        }
        else
        {
            priority = 5;
        }
    }

    int getPriority() const { return priority; }
};

class Minheap
{
    int *heap;
    int capacity;
    int currentSize;

public:
    Minheap(int cap)
    {
        capacity = cap;
        heap = new int[capacity];
        currentSize = 0;
    }

    void heapify(int i)
    {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= currentSize && heap[left] < heap[smallest])
            smallest = left;

        if (right <= currentSize && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    void insert(int val)
    {
        if (currentSize == capacity)
        {
            cout << "HEAP IS FULL!" << endl;
            return;
        }

        currentSize++;
        int i = currentSize;
        heap[i] = val;

        while (i > 1 && heap[i / 2] > heap[i])
        {
            swap(heap[i / 2], heap[i]);
            i = i / 2;
        }
    }

    void delete_heap()
    {
        if (isEmpty())
        {
            cout << "HEAP IS EMPTY!" << endl;
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
            cout << "HEAP IS EMPTY!" << endl;
            return;
        }

        for (int i = 1; i <= currentSize; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty() const { return currentSize == 0; }
};

int main()
{

    Minheap heap(10);

    // Insert some package priorities into the heap
    heap.insert(3); // Medium priority
    heap.insert(5); // Low-priority
    heap.insert(1); // High-priority
    heap.insert(4); // Medium-low priority
    heap.print_heap();

    // New package with priority 2
    Package newPackage("12:00 PM", "medium-high");
    int newPriority = 2;

    // Insert the new package's priority
    heap.insert(newPriority);
    heap.print_heap();

    return 0;
}
