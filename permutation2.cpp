#include<iostream>
using namespace std;

void toggle(char &s)
{
   if(isupper(s))
   {
    s=tolower(s);
   }
   else
   {
    if(islower(s))
    {
      s=toupper(s);
    }
   }
}

void permutation(string h,int index)
{
  if(index==h.size())
  {
    cout<<h<<endl;
    return;
  }
  
  permutation(h,index+1);

  if((h[index]>=65 && h[index]<=90 )|| (h[index]>=97 && h[index]<=122))
  {
    toggle(h[index]);
    permutation(h,index+1);
    toggle(h[index]);

  }
 

}

int main()
{
  string hello;
  cout<<"Enter a string:";
  cin>>hello;

  permutation(hello,0);
return 0;
}
