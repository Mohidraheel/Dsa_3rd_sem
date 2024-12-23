#include<iostream>
using namespace std;

bool issafe(char **arr,int row,int col,int n,int index,string word)
{
  if(row<0 || row >=n || col <0 || col >=n ||(arr[row][col]!=word[index] ))
  {
    return false;
  }
  return true;
}

bool wordsearch(char **arr,int i,int j,int n,string word,int index)
{
  if(index==word.length())
  {
    return true;
  }
  if(issafe(arr,i,j,n,index,word))
  {
   char temp=arr[i][j];
   arr[i][j]='#';
    if(wordsearch(arr,i+1,j,n,word,index+1))
    {
      return true;
    }
    if(wordsearch(arr,i,j+1,n,word,index+1))
    {
      return true;
    }
    if(wordsearch(arr,i-1,j,n,word,index+1))
    {
      return true;
    }
    if(wordsearch(arr,i,j-1,n,word,index+1))
    {
      return true;
    }
    arr[i][j]=temp;
  }
    return false;

  
  

}

int main()
{
  char intialarr[4][4]={
        {'A', 'B', 'C', 'I'},
        {'S', 'F', 'H', 'S'},
        {'A', 'O', 'E', 'E'},
        {'M','M' , 'N','N'}
  };
  
  char **arr=new char*[4];
  for(int i=0;i<4;i++)
  {
    arr[i]=new char[4];
  }
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
      arr[i][j]=intialarr[i][j];
    }
  }
  bool found=false;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<4;j++)
    {
       if(wordsearch(arr,i,j,4,"MOFB",0))
       {
        found=true;
       }

    }
    if(found)
    {
      break;
    }
  }

  if(found)
  {
    cout<<"found word"<<endl;
  }
  else
  {
    cout<<"Not Found"<<endl;
  }

  for (int i = 0; i < 4; i++) {
        delete[] arr[i];
    }
    delete[] arr;



return 0;
}
