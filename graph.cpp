#include<iostream>
using namespace std;


class graph
{
  int v;
  int **adjencylist;
  public:
  graph(int v)
  {
    this->v=v;
    adjencylist=new int*[v]();
    for(int i=0;i<v;i++)
    {
      adjencylist[i]=new int[v]();
    }

  }
  void addedge(int u,int v)
  {
    adjencylist[u][v]=1;
  }
  void dfsutiil(int startindex,bool visited[])
  {
    visited[startindex]=true;
    cout<<startindex<<" ";
    for(int i=startindex;i < v;i++)
    {
      if(adjencylist[startindex][i] && !visited[i])
      {
        dfsutiil(i,visited);
      }
    }

  }
  void dfs(int startindex)
  {
    bool *visited=new bool[v]();
    
      dfsutiil(startindex,visited);
    
    delete[] visited;
  }

  void bfs(int startindex)
  {
    bool *visited=new bool[v];
    int *queue=new int[v];
    int front=0,rear=0;
    queue[rear++]=startindex;
    visited[startindex]=true;
    while(front!=rear)
    {
      int i=queue[front++];
      cout<<i<<" ";
      for(int j=0;j<v;j++)
      {
        if(adjencylist[i][j] && !visited[j])
        {
          visited[j]=true;
          queue[rear++]=j;
        }
      }
    }
  }

};
int main()
{
return 0;
}
