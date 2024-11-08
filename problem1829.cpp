class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int max_k = (1 << maximumBit) - 1; // Maximum value for k (all bits set to 1 in maximumBit length)
        int xor_sum = 0;
        
        // Calculate initial xor_sum of all elements in nums
        for (int num : nums) {
            xor_sum ^= num;
        }
        
        vector<int> result;
        // Iterate backwards to simulate removing the last element after each query
        for (int i = nums.size() - 1; i >= 0; --i) {
            result.push_back(xor_sum ^ max_k); // Calculate the best k for current xor_sum
            xor_sum ^= nums[i]; // Remove the last element from xor_sum
        }
        
        return result;
    }
};
