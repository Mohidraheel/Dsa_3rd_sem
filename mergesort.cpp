#include<iostream>
using namespace std;
void merge(int *arr,int l,int m,int h,int n,int *arr1)
{
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            arr1[k]=arr[i];
            i++;

        }
        else
        {
            arr1[k]=arr[j];
            j++;

        }
        k++;
    }

        while(j<=h)
        {
            arr1[k]=arr[j];
            k++;
            j++;
        }
    
    
         while(i<=m)
        {
            arr1[k]=arr[i];
            k++;
            i++;
        }
        for (int i = l; i <= h; i++) {
        arr[i] = arr1[i];
    }
    
}
void mergesort(int *arr,int n,int low,int high,int *arr1)
{
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    mergesort(arr,n,low,mid,arr1);
    mergesort(arr,n,mid+1,high,arr1);
    merge(arr,low,mid,high,n,arr1);
}
int main() {
    int *arr=new int[9];
    int *arr1 = new int[9];  
    cout << "Enter the elements: ";
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    mergesort(arr,9, 0, 8,arr1);

    cout << "Sorted array: ";
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr1;  
    return 0;
}