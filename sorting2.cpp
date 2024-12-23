#include<iostream>
using namespace std;

void shellsort(int *arr,int n)
{
  int gap=n/2;
  for(;gap>=1;gap=gap/2)
  {
    for(int j=gap;j<n;j++)
    {
      for(int i=j-gap;i>=0;i=i-gap)
      {
        if(arr[i+gap]>arr[i])
        {
          break;
        }
        else
         {
          swap(arr[i+gap],arr[i]);
         }
      }
    }
  }

}


void combsort(int *arr,int n)
{
  bool swapped=true;
  int gap=n;
  while(gap>1 || swapped)
  {
    gap=gap/1.3;
    if(gap<1)
    {
      gap=1;
    }
    swapped = false;
    for(int i=0;i+gap<n;i++)
    {
      if(arr[i+gap]<arr[i])
      {
        swap(arr[i],arr[i+gap]);
        swapped=true;
      }
    
    }
  }
  
}
void print(int *arr,int n)
{
   for(int i=0;i<n;i++)
   {
    cout<<arr[i]<<" ";
   }
}
int main()
{
  int arr[8]={29,23,15,3,10,2,4,1};
  shellsort(arr,8);
  print(arr,8);
  cout<<endl;
  int arr1[6]={3,7,1,4,6,2};
  combsort(arr1,6);
  print(arr1,6);
  
return 0;
}
                                                                                