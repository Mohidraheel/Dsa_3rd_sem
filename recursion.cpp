// #include<iostream>
// using namespace std;

// int issorted(int arr[],int size,int count,int sum)
// {
//   if(count==size)
//   {
//     return sum;
//   }
//   else
//   {
//     if(count<size)
//     {
//       sum+=arr[count];
//       issorted(arr,size,count+1,sum);
//     }
//   }
 

// }

// int main()
// {

//   int arr[5]={3,2,5,1,6};
//   int n=5;
//   int s=issorted(arr,n,0,0);
//   cout<<s;
  

//   return 0;
// }


// linear search






// #include<iostream>
// using namespace std;

// bool isfound(int arr[],int size,int count,int key)
// {
//   if(count==size)
//   {
//     return false;
//   }

//   if(count<size)
//   {
//     if(arr[count]==key)
//     {
//       return true;
//     }
//     else
//     {
//       return isfound(arr,size,count+1,key);
//     }
//   }
// }





// int main()
// {
//   int arr[5]={3,2,5,1,6};
//   int n=5;
//   int key=8;

//   bool ans=isfound(arr,5,0,key);
//   cout<<ans;


// return 0;
// }

//binary search
#include<iostream>
using namespace std;

void sort(int *arr,int n)
{
  int temp;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
      {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  cout<<"sorted array is:"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
}

int mid=0;
bool isfound(int arr[],int start,int end,int key)
{
  if(start>end)
  {
    return false;

  }

  if(start<end)
  {
    mid=(start+end)/2;
    if(arr[mid]==key)
    {
      cout<<"index:"<<mid<<endl;
      return true;
    }
    else
    {
      if(arr[mid]<key)
      {
        return isfound(arr,mid+1,end,key);
      }
      else
      {
        return isfound(arr,start,mid-1,key);
      }
    }
  }

}
int main()
{
  int arr[5]={3,2,5,1,6};
  int n=5;
  sort(arr,n);
  bool ans=isfound(arr,0,n-1,5);
  if(ans)
  {
    cout<<"element found";
  }
  else
  {
    cout<<"element not found";
  }
 
  
return 0;
}
