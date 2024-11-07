#include <vector>
#include <algorithm>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int maxSize = 0;
        
        // Check each bit position from 0 to 23
        for (int bit = 0; bit < 24; ++bit) {
            int count = 0;
            
            // Count how many numbers have the current bit set
            for (int num : candidates) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            // Update the maximum subset size
            maxSize = std::max(maxSize, count);
        }
        
        return maxSize;
    }
};
