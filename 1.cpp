#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= n && arr[left] > arr[largest])
  {
    largest = left;
  }

  if (right <= n && arr[right] > arr[largest])
  {
    largest = right;
  }

  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    maxHeapify(arr, n, largest);
  }
}

void buildMaxHeap(int arr[], int n)
{
  for (int i = n / 2; i >= 1; --i)
  {
    maxHeapify(arr, n, i);
  }
}

void minHeapify(int arr[], int n, int i)
{
  int smallest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= n && arr[left] < arr[smallest])
  {
    smallest = left;
  }

  if (right <= n && arr[right] < arr[smallest])
  {
    smallest = right;
  }

  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);
    minHeapify(arr, n, smallest);
  }
}

void buildMinHeap(int arr[], int n)
{
  for (int i = n / 2; i >= 1; --i)
  {
    minHeapify(arr, n, i);
  }
}

void maxHeapSort(int arr[], int n)
{
  buildMaxHeap(arr, n);
  for (int i = n; i > 1; --i)
  {
    swap(arr[1], arr[i]);
    maxHeapify(arr, i - 1, 1);
  }
}

void minHeapSort(int arr[], int n)
{
  buildMinHeap(arr, n);
  for (int i = n; i > 1; --i)
  {
    swap(arr[1], arr[i]);
    minHeapify(arr, i - 1, 1);
  }
}
int deleteMax(int arr[], int &n)
{
  if (n == 0)
  {
    cout << "Heap is empty.\n";
    return -1;
  }

  int maxVal = arr[1];   // Store the maximum value (root)
  arr[1] = arr[n];       // Replace root with the last element
  --n;                   // Reduce the heap size
  maxHeapify(arr, n, 1); // Restore Max Heap property

  return maxVal; // Return the deleted value
}

// Delete from Min Heap
int deleteMin(int arr[], int &n)
{
  if (n == 0)
  {
    cout << "Heap is empty.\n";
    return -1;
  }

  int minVal = arr[1];   // Store the minimum value (root)
  arr[1] = arr[n];       // Replace root with the last element
  --n;                   // Reduce the heap size
  minHeapify(arr, n, 1); // Restore Min Heap property

  return minVal; // Return the deleted value
}

void printArray(int arr[], int n)
{
  for (int i = 1; i <= n; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int maxSize = 100;
  int arr[100 + 1]; // Index 0 will remain unused
  int n;

  cout << "Enter the number of elements (max 100): ";
  cin >> n;

  cout << "Enter the array elements separated by spaces: ";
  for (int i = 1; i <= n; ++i)
  {
    cin >> arr[i];
  }

  int choice;
  while (true)
  {
    cout << "\nMenu:\n";
    cout << "1. Create Max Heap\n";
    cout << "2. Create Min Heap\n";
    cout << "3. Sort Max Heap\n";
    cout << "4. Sort Min Heap\n";
    cout << "5. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      buildMaxHeap(arr, n);
      cout << "Max Heap: ";
      printArray(arr, n);
      break;
    case 2:
      buildMinHeap(arr, n);
      cout << "Min Heap: ";
      printArray(arr, n);
      break;
    case 3:
      maxHeapSort(arr, n);
      cout << "Sorted in Ascending Order (Max Heap): ";
      printArray(arr, n);
      break;
    case 4:
      minHeapSort(arr, n);
      cout << "Sorted in Descending Order (Min Heap): ";
      printArray(arr, n);
      break;
    case 5:
      return 0;
    default:
      cout << "Invalid choice. Please enter a valid option.\n";
    }
  }
}
