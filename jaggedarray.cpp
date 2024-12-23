#include<iostream>
#include<vector>
using namespace std;
int main()
{
  // Using vectors
vector<vector<int>>jaggedarray;
  int rows, cols,element;
  cout << "Enter the number of rows: ";
  cin >> rows;
  for(int i = 0; i < rows; i++)
  {
    cout << "Enter the number of columns for row " << i + 1 << ": ";
    cin >> cols;
    vector<int>row;
    for(int j = 0; j < cols; j++)
    {
      cout << "Enter element at (" << i + 1 << "," << j + 1 << "): ";
      cin>> element;
      row.push_back(element);
      element=0;
    }
    jaggedarray.push_back(row);

  }

  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < jaggedarray[i].size(); j++)
    {
      cout << jaggedarray[i][j] << " ";
    }
    cout << endl;
  }



    // using pointers
    cout<<endl;
    cout<<"________________________________________________________________"<<endl;
    int r;
    cout << "Enter the number of rows: ";
    cin >>r;
    int **arr=new int*[r];
    int *col=new int[r];
    for(int i = 0; i < r; i++)
    {
       cout << "Enter the number of columns for row " << i + 1 << ": ";
       cin >> col[i];

       arr[i]=new int[col[i]];
    }
    for(int i = 0; i < r; i++) {
      {
         cout<<"Enter Element for row "<<i+1<<" "<<"";
        for(int j = 0; j < col[i]; j++) {
         
          cin>>arr[i][j];
        }

      }
    }
      for(int i=0;i<r;i++)
      {
        for(int j=0;j<col[i];j++)
        {
          cout<<arr[i][j]<<" ";
        }
        cout<<endl;
      }

      for(int i=0;i<r;i++)
      {
        delete[] arr[i];
      }
      delete[] arr;

return 0;
}
