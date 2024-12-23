#include <iostream>
#include <vector>
using namespace std;

class heap {
    vector<pair<int, int>> maxheap;
    int size;
    int count;

public:
    heap(int s) {
        size = s + 1; 
        count = 0;
        maxheap.resize(size, {-1, -1});
    }

    bool compare(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first) {
            return true;
        }
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return false;
    }

    void heapify(int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= count && compare(maxheap[left], maxheap[largest])) {
            largest = left;
        }
        if (right <= count && compare(maxheap[right], maxheap[largest])) {
            largest = right;
        }

        if (largest != i) {
            swap(maxheap[i], maxheap[largest]);
            heapify(largest);
        }
    }

    void insert(pair<int, int> item) {
        if (count == size - 1) {
            cout << "Heap is full. Cannot insert\n";
            return;
        }
        count++;
        maxheap[count] = item;

        int i = count;
        while (i > 1 && compare(maxheap[i], maxheap[i / 2])) {
            swap(maxheap[i], maxheap[i / 2]);
            i = i / 2;
        }
    }

    pair<int, int> deletion() {
        if (count == 0) {
            cout << "Heap is empty. Cannot delete\n";
            return {0, 0};
        }

        pair<int, int> max = maxheap[1];
        maxheap[1] = maxheap[count];
        count--;
        heapify(1);

        return max;
    }

    void display() {
        cout << "Heap elements: \n";
        for (int i = 1; i <= count; i++) {
            cout << maxheap[i].first << " " << maxheap[i].second << endl;
        }
        cout << endl;
    }

    void sorting() {
        int temp = count;

        while (count > 1) {
            swap(maxheap[1], maxheap[count]);
            count--;
            heapify(1);
        }

        cout << "Sorted array in Ascending order: \n";
        for (int i = 1; i <= temp; i++) {
            cout << maxheap[i].first << " " << maxheap[i].second << endl;
        }

        count = temp; 
    }
};

int main() {
    heap h(5);

    h.insert({3, 1});
    h.insert({2, 2});
    h.insert({1, 3});
    h.insert({5, 4});
    h.insert({4, 5});

    h.display();

    pair<int, int> p = h.deletion();
    cout << "Deleted element: (" << p.first << ", " << p.second << ")\n";

    h.sorting();

    return 0;
}
