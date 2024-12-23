#include<iostream>
using namespace std;

void permutations(string h,int left)
{
  if(left==h.size()-1)
  {
    cout<<h<<endl;
    return;
  }
  else
  {
    for(int i=left;i<h.size();i++)
    {
      swap(h[i],h[left]);
      permutations(h,left+1);
      swap(h[i],h[left]);
    }
  }
}

int main()
{
  string hello;
  cout<<"Enter a string:";
  cin>>hello;

  permutations(hello,0);

return 0;
}
