#include<iostream>
using namespace std;

void selectionsort(int *arr,int n)
{
  int min;
  for(int i=0;i<n;i++)
  {
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(arr[min]>arr[j])
      {
        min=j;
      }

    }
    if(min!=i)
    {
      swap(arr[i],arr[min]);
    }


  }
}
void insertionsort(int *arr,int n)
{
  int key;
  for(int i=1;i<n;i++)
  {
    key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
}

bool binarysearch(int *arr,int n,int key)
{
  int low=0;
  int high=n;
  int mid;
  while(low<high)
  {
     mid=(low+high)/2;
     if(arr[mid]==key)
     {
      return true;
     }
     if(arr[mid]>key)
     {
      high=mid-1;
     }
     else
     {
      low=mid+1;
     }
  }
  return false;
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
  int n=8;
  int arr[8]={6,3,1,7,4,8,2,9};
  insertionsort(arr,8);
  print(arr,8);
 if( binarysearch(arr,8,10))
 {
  cout<<"found";
 }
 else
 {
  cout<<"nikal";
 }

return 0;
}
