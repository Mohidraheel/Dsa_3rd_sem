#include <iostream>
#include <vector>
using namespace std;

class linearprobing
{
  int *arr;
  int size;
  int counts;
  int hashfunction(int key)
  {
    return key % size;
  }

public:
  linearprobing(int size)
  {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = -1;
    }
    counts = 0;
  }

  void insert(int key)
  {
    int index = hashfunction(key);
    while (arr[index] != -1)
    {
      index = (index + 1) % size;
    }
    arr[index] = key;
    counts++;
  }

  void count(vector<int> arr1, vector<int> &arr2)
  {
    for (int i = 0; i < arr1.size(); i++)
    {
      int key = arr1[i];
      int frequency = 0;
      for (int j = 0; j < counts; j++)
      {
        if (arr[j] == key)
        {
          frequency++;
        }
      }
      arr2[i] = frequency;
    }
  }
};

vector<int> findnums(const vector<int> &arr)
{
  vector<int> arr2;                 // To store unique elements
  vector<bool> visited(arr.size()); // To check if an element is already processed

  for (int i = 0; i < arr.size(); i++)
  {
    if (!visited[i])
    {
      bool isDuplicate = false;

      for (int j = i + 1; j < arr.size(); j++)
      {
        if (arr[i] == arr[j])
        {
          visited[j] = true; // Mark duplicate elements
          isDuplicate = true;
        }
      }

      // Push the number if it's unique or the first occurrence of duplicates
      if (!isDuplicate)
      {
        arr2.push_back(arr[i]);
      }
    }
  }
  return arr2;
}

// Merge function
void merge(int arr[],int arr2[] ,int low, int mid, int high)
{
  int i = low;
  int j = mid + 1;
  int k = low;
  while (i <= mid && j <= high)
  {
    if (arr[i] >= arr[j]) // Compare frequencies
    {
      arr2[k] = arr[i];
      k++;
      i++;
    }
    else
    {
      arr2[k] = arr[j];
      k++;
      j++;
    }
  }
  while (i <= mid)
  {
    arr2[k] = arr[i];
    k++;
    i++;
  }
  while (j <= high)
  {
    arr2[k] = arr[j];
    k++;
    j++;
  }
}

void mergesort(int arr[],int arr2[] ,int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr,arr2 ,low, mid);
    mergesort(arr,arr2 ,mid + 1, high);
    merge(arr,arr2 ,low, mid, high);
  }
}

int main()
{
  linearprobing obj(12);
  obj.insert(5);
  obj.insert(4);
  obj.insert(3);
  obj.insert(5);
  obj.insert(5);
  obj.insert(4);
  obj.insert(2);
  obj.insert(4);
  obj.insert(5);
  obj.insert(3);
  obj.insert(3);
  obj.insert(3);

  vector<int> arr1 = {5, 4, 3, 2};
  vector<int> arr2(arr1.size(), 0);
  obj.count(arr1, arr2);

  cout << "Frequency of each unique number in arr1: " << endl;
  for (int i = 0; i < arr1.size(); i++)
  {
    cout << arr1[i] << " : " << arr2[i] << endl;
  }

  int *arr = new int[arr1.size()];
  int *freq = new int[arr1.size()];

  // Copy elements and frequencies to arrays
  for (int i = 0; i < arr1.size(); i++)
  {
    arr[i] = arr1[i];
    freq[i] = arr2[i];
  }
   int *freq2 = new int[arr1.size()];
  mergesort(freq,freq2 ,0, arr1.size() - 1);
  cout << "\nFrequency of each unique number in arr1, sorted by frequency: " << endl;
  for (int i = 0; i < arr1.size(); i++)
  {
    cout << freq2[i] << endl;
  }


  return 0;
}
