#include <iostream>
#include <vector>
using namespace std;

bool issafe(int **arr, int x, int y, int **visit, int n)
{
  if ((x < n && x >= 0) && (y < n && y >= 0) && (arr[x][y] == 1) && (visit[x][y] == 0))
  {
    return true;
  }
  return false;
}
void solve(int **arr, int n, int r, int c, int **visited, string path,vector<string>&allpath)
{
  if ((r == n - 1 && c == n - 1))
  {
    allpath.push_back(path);

    return;
  }
  
  visited[r][c] = 1;
  // down
  if (issafe(arr, r + 1, c, visited, n))
  {
     solve(arr, n, r + 1, c, visited, path + 'D',allpath);
    
  }
  // right
  if (issafe(arr, r, c + 1, visited, n))
  {
     solve(arr, n, r, c + 1, visited, path + 'R',allpath);
    
  }
  visited[r][c] = 0;

  return ;
}


bool ratinamaze(int **arr, int n, int r, int c, int **visited)
{
  if ((r == n - 1) && (c == n - 1))
  {
    visited[r][c] = 1;
    return true;
  }
  if (issafe(arr, r, c, visited, n))
  {
    visited[r][c] = 1;
    if (ratinamaze(arr, n, r + 1, c, visited))
    {
      return true;
    }
    if (ratinamaze(arr, n, r, c + 1, visited))
    {
      return true;
    }
    visited[r][c] = 0;
    return false;
  }
  return false;
}

int main()
{
  int n = 5;

  int **arr = new int *[n];
  int **visited = new int *[n];
  vector<string>path;
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
    visited[i] = new int[n];
  }

  int initialArr[5][5] = {
      {1, 0, 1, 0, 1},
      {1, 1, 1, 1, 1},
      {0, 0, 1, 1, 0},
      {1, 0, 1, 1, 1},
      {1, 1, 1, 0, 1}};

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      arr[i][j] = initialArr[i][j];
      visited[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  solve(arr, n, 0, 0, visited, "",path);
   for(int i=0;i<path.size();i++)
   {
    cout<<path[i]<<endl;
   }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      visited[i][j] = 0;
    }
  }

  cout<<"Numbers of Path:"<<path.size()<<endl;

  bool pathExists = ratinamaze(arr, n, 0, 0, visited);
  if (pathExists)
  {
    cout << "Path found" << endl;
  }
  else
  {
    cout << "No path found" << endl;
  }

  for (int i = 0; i < n; i++)
  {
    delete[] arr[i];
    delete[] visited[i];
  }
  delete[] arr;
  delete[] visited;

  return 0;
}


