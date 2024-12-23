#include <iostream>
#include <vector>

using namespace std;


void insertionsort(vector<int>&arr,int n)
{
    int current, j;

    for(int i=1;i<n;i++)
    {
        current=arr[i];
         j=i-1;
        while(j>=0 && current < arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;        
    }
}
void print(vector<int>&arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}
int main()
{
    int n;
    cout << "enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "enter elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionsort(arr,n);
    cout << "sorted array: ";
    print(arr, n);
    
    return 0;
}
