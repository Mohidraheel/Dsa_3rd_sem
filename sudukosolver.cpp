#include<iostream>
using namespace std;
bool issafe(int **arr,int row,int col,int n,int value)
{
  for(int i=0;i<row;i++)
  {
    if(arr[i][col]==value)
    {
      return false;
    }

  }

  for(int i=0;i<col;i++)
  {
     if(arr[row][i]==value)
    {
      return false;
    }
  }


  int startrow=row-row%3 ;
  int startcol=col -col%3;

  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
       if(arr[i+startrow][j+startcol]==value)
       {
        return false;
       }
    }
  }

  return true;

 

  

}

bool suduko(int **arr,int n)
{
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(arr[i][j]==0)
      {
         for(int val=1;val<=9;val++)
         {
            if(issafe(arr,i,j,n,val))
            {
              arr[i][j]=val;
               if(suduko(arr,n))
               {
                return true;
               }
               else
               {
                arr[i][j]=0;
               }
            }
         }
      return false;
      }
    }
  }

  return true;
}

int main()
{
  int carr[9][9]=
  {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
  };

  int **arr=new int*[9];
  for(int i=0;i<9;i++)
  {
    arr[i]=new int[9];
    for(int j=0;j<9;j++)
    {
      arr[i][j]=carr[i][j];
    }
  }

  if(suduko(arr,9))
  {
    cout<<"Solution exist"<<endl;
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
      {
        cout<<arr[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  else
  {
    cout<<"Not possible"<<endl;
  }
return 0;
}
