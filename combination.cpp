#include <iostream>
using namespace std;

void combinations(int arr[], int n, int target, int index, int ans[][10], int &ansIndex, int temp[], int tempSize)
{
    // Base case: if target is less than 0 or index goes out of bounds
   if(index >=n || target < 0)
   {
    return;
   }
   if(target==0)
   {
    for(int i=0;i<tempSize;i++)
    {
        ans[ansIndex][i]=temp[i];
    }
    ans[ansIndex][tempSize]=-1;
    ansIndex++;
    return;
   }

   temp[tempSize]=arr[index];

   combinations(arr,n,target-arr[index],index,ans,ansIndex,temp,tempSize+1);
   combinations(arr,n,target,index+1,ans,ansIndex,temp,tempSize);
}

int main()
{
    int arr[3] = {1, 2,3};
    int target = 6;

    // Arrays to store the results
    int ans[10][10]; // Array to store combinations, -1 indicates the end of each combination
    int temp[10];    // Array to store the current combination
    int ansIndex = 0; // Keeps track of how many combinations are found

    // Generate combinations
    combinations(arr, 3, target, 0, ans, ansIndex, temp, 0);

    // Print the generated combinations
    for (int i = 0; i < ansIndex; i++)
    {
        int j = 0;
        while (ans[i][j] != -1) // -1 marks the end of the combination
        {
            cout << ans[i][j] << " ";
            j++;
        }
        cout << endl;
    }

    return 0;
}
