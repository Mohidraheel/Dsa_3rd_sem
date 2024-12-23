#include <iostream>
#include <vector>
using namespace std;

void sorting(vector<int>& arr,int n)
{
    for(int i=n-1;i>=0;i++)
    {
        bool flag=false;
        int j=0;
        while(j!=i)
        {
            if(arr[j+1]!=0 && arr[j]==0)
            {
                swap(arr[j],arr[j+1]);
                flag=true;
            }
            j++;
        }
        if(!flag)
        {
            break;
        }
    }
}
void print(vector<int>& arr,int n)
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
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sorting(arr, n);
    cout << "Sorted array: ";
    print(arr, n);
    return 0;
}
