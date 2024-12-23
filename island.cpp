#include <iostream>
using namespace std;

bool issafe(int **arr, int row, int col, int r, int c)
{
  if (r < row && r >= 0 && c < col && c >= 0 &&arr[r][c]==1)
  {
    return true;
  }
  return false;
}

void island(int **arr, int i, int j, int row, int col)
{
  if(!issafe(arr,row,col,i,j))
  {
    return;
  }
  else
  {
    
    arr[i][j]=2;
    island(arr, i + 1, j, row, col);
    island(arr, i - 1, j, row, col);
    island(arr, i, j + 1, row, col);
    island(arr, i, j - 1, row, col);
  }


}

int counttotal(int **arr, int row, int col)
{
  
  
  int count = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (arr[i][j] == 1 )
      {
        island(arr, i, j, row, col);
        count++;
      }
    }
  }

  return count;
}

int main()
{
  int matrix[4][5] = {
      {1, 1, 0, 1, 0},
      {1, 1, 0, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0}};

  int **arr = new int *[4];
  for (int i = 0; i < 4; i++)
  {
    arr[i] = new int[5];
    for (int j = 0; j < 5; j++)
    {
      arr[i][j] = matrix[i][j];
    }
  }
  int count = 0;
  count = counttotal(arr, 4, 5);

  cout << "islands: " << count << endl;

   for (int i = 0; i < 4; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}