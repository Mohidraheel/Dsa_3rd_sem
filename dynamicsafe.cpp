#include <iostream>
using namespace std;

class dynamicsafearray
{
  int *arr;
  int size;

public:
  dynamicsafearray(int size)
  {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++)
    {
      arr[i] = 0;
    }
  }

  dynamicsafearray(const dynamicsafearray &obj)
  {
    size = obj.size;
    for (int i = 0; i < size; i++)
    {
      arr[i] = obj.arr[i];
    }
  }

  void resize(int s)
  {
    if (s < size)
    {
      size = s;
    }
    else
    {
      int *temp;
      temp = new int[size];
      for (int i = 0; i < size; i++)
      {
        temp[i] = arr[i];
      }

      delete arr;
      arr = new int[s];
      for (int i = 0; i < s; i++)
      {
        arr[i] = 0;
      }
      for (int i = 0; i < size; i++)
      {
        arr[i] = temp[i];
      }
      delete temp;
      for (int i = size; i < s; i++)
      {
        cout << "Enter value:" << endl;
        cin >> arr[i];
      }
      size = s;
    }
  }
  void print()
  {
    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << endl;
    }
  }

  void setdata()
  {
    cout << "Enter value:" << endl;

    for (int i = 0; i < size; i++)
    {
      cin >> arr[i];
    }
  }
};
int main()
{
  dynamicsafearray d1(5);
  d1.setdata();
  d1.resize(7);
  d1.print();
  return 0;
}
