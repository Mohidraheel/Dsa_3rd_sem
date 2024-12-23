#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int* array; 
    int capacity;  
    int size;  
    
    PriorityQueue(int c) {
        capacity = c;
        size = 0;
        array = new int[capacity];
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void resize() {
        capacity *= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && array[left] > array[largest]) {
            largest = left;
        }
        if (right < size && array[right] > array[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(largest);
        }
    }

    void push(int value) {
        if (size == capacity) {
            resize(); 
        }

        int i = size;
        array[i] = value;
        size++;

        while (i != 0 && array[(i - 1) / 2] < array[i]) {
            swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int pop() {
        if (size <= 0) {
            cout << "Priority Queue is empty. Cannot remove element.\n";
            return -1;
        }
        int max = array[0];
        array[0] = array[size - 1];
        size--;
        heapify(0);
        return max;
    }

    int top() const {
        if (size <= 0) {
            cout << "Priority Queue is empty.\n";
            return -1;
        }
        return array[0];
    }

    bool isEmpty() const {
        return size == 0;
    }

    ~PriorityQueue() {
        delete[] array;
    }
};

int main() {
    PriorityQueue pq(5);
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(5);
    pq.push(4);
    pq.push(9); 

    cout << "Top element: " << pq.top() << endl; 
    cout << "Elements in priority order:\n";
    while (!pq.isEmpty()) {
        cout << pq.pop() << " ";
    }
    cout << endl;
    return 0;
}
