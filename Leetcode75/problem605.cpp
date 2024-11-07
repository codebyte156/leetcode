#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int count = 0;
        int length = flowerbed.size();
        
        for (int i = 0; i < length; ++i) {
            // Check if the current spot is empty and can have a flower planted
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == length - 1 || flowerbed[i + 1] == 0)) {
                
                // Place a flower here
                flowerbed[i] = 1;
                count++;
                i++;
                
                // If we have planted enough flowers, return true
                if (count >= n) {
                    return true;
                }
            }
        }
        
        // Return true if we could plant all required flowers, false otherwise
        return count >= n;
    }
};
