#include<iostream>
using namespace std;
int main()
{
  bool **cinema=new bool*[4];
  int seat[4]={2,5,6,8};
  for(int i=0;i<4;i++)
  {
    cinema[i] = new bool[seat[i]];
  }

  for(int i=0;i<4;i++)
  {
    for(int j=0;j<seat[i];j++)
    {
      cinema[i][j]=false;
    }
  }
  int count=4;
   for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < seat[i]; j++)
    {
      if (count % 2 == 0)
      {
        cinema[i][j] = true; 
      }
      count++;
    }
    count++; 
  }

  for(int i=0;i<4;i++)
  {
    for(int j=0;j<seat[i];j++)
    {
      cout<<cinema[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=0;i<4;i++)
  {
    delete[] cinema[i];
  }

  delete[] cinema;


return 0;
}
