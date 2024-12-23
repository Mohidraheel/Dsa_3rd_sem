// #include<iostream>
// using namespace std;
// void selectionsort(int arr[],int n)
// {
//     int min;
//     for(int i=0;i<n-1;i++)
//     {
//         min=i;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[min])
//                 min=j;
//         }
//         if(min!=i)
//         {
//             swap(arr[i],arr[min]);
//         }
        
//     }
// }

// void print(int arr[],int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     int n;
//     cout<<"Enter the number of elements: ";
//     cin>>n;
//     int *arr=new int[n];
//     cout<<"Enter the elements: ";
//     for(int i=0; i<n; i++)
//      {   
//         cin>>arr[i];
//      }
//      selectionsort(arr,n);
//      cout<<"Sorted array: ";
//      print(arr,n);
//      delete[] arr;
    
// return 0;
// }

// using vector

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int>& arr,int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
            swap(arr[i],arr[min]);
    }

}

void print(vector<int>& arr, int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"Sorted array: ";
    print(arr,n);
    return 0;
}