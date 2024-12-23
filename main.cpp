#include<iostream>
#include"sum.h"
using namespace std;
int main()
{
  int y= sumOftwonumber(5,7);
  cout<<"The sum is: "<<y<<endl;

  int arr[5]={1,2,3,4,5};
  printarray(arr,5);
 cout<<endl;
 changearray(arr,5);
  printarray(arr,5);


return 0;
}
