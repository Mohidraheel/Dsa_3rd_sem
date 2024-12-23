#include <iostream>
using namespace std;

void generateSubsets(int arr[], int n, int index, int current[], int currentSize, int ans[][10], int &ansIndex)
{
    // Base case: if we've considered all elements
    if(index==n)
    {
        for(int i=0;i<currentSize;i++)
        {
            ans[ansIndex][i]=current[i];
        }
        ans[ansIndex][currentSize]=-1;
        ansIndex++;
        return;
    }

    generateSubsets(arr,n,index+1,current,currentSize,ans,ansIndex);
     current[currentSize]=arr[index];
     generateSubsets(arr,n,index+1,current,currentSize+1,ans,ansIndex);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int current[5];
    int ans[32][10]; // Array to store subsets, -1 indicates the end of each subset
    int ansIndex = 0;

    // Generate all subsets using recursion with arrays
    generateSubsets(arr, 5, 0, current, 0, ans, ansIndex);

    // Print the generated subsets
    for (int i = 0; i < ansIndex; i++)
    {
        int j = 0;
        while (ans[i][j] != -1) // -1 marks the end of the subset
        {
            cout<<ans[i][j] << " ";
            j++;
        }
        cout << endl;
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// void generateSubsets(int arr[], int n, int index, vector<int> &current, vector<vector<int>> &ans)
// {
//   // Base case: if we've considered all elements
//   if (index == n)
//   {
//     ans.push_back(current); // Add the current subset to the answer
//     return;
//   }


//   generateSubsets(arr, n, index + 1, current, ans);

//   current.push_back(arr[index]);
//   generateSubsets(arr, n, index + 1, current, ans);

  
//   current.pop_back();
// }

// int main()
// {
//   int arr[4] = {1, 2, 3,4};
//   vector<vector<int>> ans;
//   vector<int> current;

//   // Generate all subsets using recursion
//   generateSubsets(arr, 4, 0, current, ans);

//   // Print the generated subsets
//   for (int i = 0; i < ans.size(); i++)
//   {
//     for (int j = 0; j < ans[i].size(); j++)
//     {
//       cout << ans[i][j] << " ";
//     }
//     cout << endl;
//   }

//   return 0;
// } 