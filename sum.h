#include<iostream>

using namespace std;

int sumOftwonumber(int a,int b)

{
  return (a+b);
}


void printarray(int arr[],int size)
{
  int i;
  for (i=0; i < size; i++)
  {
     cout << arr[i] << " ";
  }
}


void changearray(int *arr,int size)
{
  int i;
  for (i=0; i < size; i++)
  {
     arr[i] +=1 ;
  }
}