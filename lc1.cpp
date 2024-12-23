// #include<iostream>
// using namespace std;
// int main()
// {
//     int target,sum;
//     cin>>target;
//     int m,n;
//     int arr[4]={2,7,11,15};
//     for(int i=0;i<4;i++)
//     {
//         for(int j=i+1;j<4;j++)
//         {
//             if(arr[i]+arr[j]==target)
//             {
//                 m=i;
//                 n=j;
//                 break;
//             }
//         }
//     }
//     cout<<m<<" "<<n;

// }

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m, n;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    m = i;
                    n = j;
                    return {m, n};  
                }
            }
        }
        return {};  
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 6, 8};
    int target;
    cin >> target;

    vector<int> result = solution.twoSum(nums, target);
    if (!result.empty()) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
