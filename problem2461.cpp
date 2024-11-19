/*  Here I will use hash map and sliding window technique 
    as there if we directly approach the method by just making subarrays and checking for unique ele
    hence it will be O(N K) thus it will lead to 10^10 which is worst for this case, thus 
    sliding and Hmap will be used by me.
*/

class Solution {
    #define ll long long
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        ll max_sum=0;
        unordered_map<int,int> freq;

        ll win_sum=0;
        for(int i=0;i<n;++i){
            // Include right element
            freq[nums[i]]++;
            win_sum += nums[i];

            // Exclude or Delete left element
            if(i>=k){
                win_sum -= nums[i-k];
                freq[nums[i-k]]--;
                if(freq[nums[i-k]]==0)
                    freq.erase(nums[i-k]);
            }

            // Update max_sum so that the result will be returned
            if(i>=k-1 and freq.size()==k)
                max_sum = max(max_sum,win_sum);
        }
        return max_sum;
    }
};