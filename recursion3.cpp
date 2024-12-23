#include<iostream>
#include<ctime>
using namespace std;

void game(int x,int move,int playercount,int count)
{
    int y;
    count=(count %playercount) + 1;
    cout<<"Enter Your choice player " <<count<<" :"<<endl;
    cin>>y;
    if(x==y)
    {
      cout<<"Congratulations Player :"<<count<<"won"<<endl;
    }
    else
    {
      if(x> y)
      {
        cout<<"Think Higher"<<endl;
        game(x,move,playercount,count);
      }
      else
      {
        cout<<"Think Lower"<<endl;
        game(x,move,playercount,count);
      }
    }
}

int main()
{
  srand(time(NULL));

  int x = (rand() % 10)+1;
  int playercount;
  cout<<"Enter Number of Players:"<<endl;
  cin>>playercount;
  game(x,0,playercount,0);
return 0;
}
