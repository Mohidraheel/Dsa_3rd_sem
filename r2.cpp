#include<iostream>
using namespace std;


string reverseString(string& str,int i)
{
  if(i>=str.length()/2)
  {
    return str;
  }
  swap(str[i],str[str.length()-i-1]);
  return reverseString(str,i+1);
}


bool ispallindrome(string str,int i)
{
  if(i>str.length()/2)
  {
    return true;
  }
  if(str[i]!=str[str.length()-i-1])
  {
    return false;
  }
  return ispallindrome(str,i+1);
}
int main()
{
string name="abba";

cout<<"Original String: "<<name<<endl;
name=reverseString(name,0);
cout<<"Reversed String: "<<name<<endl;

bool isPalindrome=ispallindrome(name,0);

if(isPalindrome)
{
  cout<<"The string is a palindrome.";
}
else
{
  cout<<"The string is not a palindrome.";
}
return 0;
}
