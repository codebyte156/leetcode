/*
You are given an array nums of positive integers and a positive integer k.
A subset of nums is beautiful if it does not 
contain two integers with an absolute difference equal to k.
Return the number of non-empty beautiful subsets of the array nums.
A subset of nums is an array that can be obtained by deleting some 
(possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.

*/

#include <vector>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dp[1 << n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = (1 << i) - 1; j >= 0; j--) {
                if (!(j & (1 << i))) {
                    bool valid = true;
                    for (int l = 0; l < i; l++) {
                        if ((j & (1 << l)) && abs(nums[i] - nums[l]) == k) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        dp[j | (1 << i)] += dp[j];
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i < (1 << n); i++) {
            res += dp[i];
        }
        return res;
    }
};

// By R2