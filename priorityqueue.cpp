#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;  
        size = 0;
    }

    void insert(int val) {
        size++;
        arr[size] = val;
    }

    void heapify(int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        // Check if the left child exists and is greater than the current largest
        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check if the right child exists and is greater than the current largest
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If the largest is not the parent, swap and continue heapifying
        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);  // Recursively heapify the affected subtree
        }
    }

    void buildHeap() {
        // Start heapifying from the last non-leaf node to the root
        for (int i = size / 2; i > 0; i--) {
            heapify(i);
        }
    }

void deleteRoot() {
        if (size == 0) {
            cout << "Heap is empty. Nothing to delete." << endl;
            return;
        }

        // Step 1: Move the last element to the root
        arr[1] = arr[size];
        size--;

        // Step 2: Bubble down to maintain the heap property
        int index = 1;
        while (index <= size) {
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;
            int largest = index;

            if (leftChild <= size && arr[leftChild] > arr[largest]) {
                largest = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    // Insert elements directly without bubbling up (we will use buildHeap)
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(25);

    cout << "Array before building heap: ";
    h.print();

    // Build the max-heap using heapify
    h.buildHeap();

    cout << "Max-Heap after heapify: ";
    h.print();

    return 0;
}