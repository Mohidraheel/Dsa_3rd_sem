#include<iostream>
#include <vector>
using namespace std;
bool issafe(int **board,int col,int row,int n)
{
  //row
  for(int i=0;i<col;i++)
  {
    if(board[row][i])
    {
      return false;
    }
  }
  // col
  for(int i=0;i<row;i++)
  {
    if(board[i][col])
    {
      return false;
    }
  } 

  for(int i=row,j=col;i>=0 && j>=0;i--,j--)
  {
    if(board[i][j])
    {
      return false;
    }
  }

  for(int i=row, j=col;i<n && j>=0;i++,j--)
  {
    if(board[i][j])
    {
      return false;
    }
  }

  return true;

}


bool queensprob(int **board,int col,int n)
{
  if(col>=n)
  {
    return true;// queens have been placed
  }

  for(int i=0;i<n;i++)
  {
    if(issafe(board,col,i,n))
    {
      board[i][col]=1;
      if(queensprob(board,col+1,n))
      {
        return true;
      }
      board[i][col]=0;// bt
    }
  }
      return false;

}

int main()
{
  int queens;
  cout<<"Enter Number of queens: ";
  cin>>queens;

  int **matrix=new int*[queens];
  for(int i=0;i<queens;i++)
  {
    matrix[i]=new int[queens];
    for(int j=0;j<queens;j++)
    {
      matrix[i][j]=0;
    }   
  }


  if(queensprob(matrix,0,queens))
  {
    for(int i=0;i<queens;i++)
    {
      for(int j=0;j<queens;j++)
      {
        cout<<matrix[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  else
  {
    cout<<"No Solution Exist"<<endl;
  }




  for (int i = 0; i < queens; i++)
{
    delete[] matrix[i];
}
delete[] matrix;

return 0;
}

