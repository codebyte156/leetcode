#include <vector>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        // If the number of cards is not divisible by groupSize, return false
        if (n % groupSize != 0) {
            return false;
        }
        
        // Count the occurrences of each card value
        std::map<int, int> counter;
        for (int card : hand) {
            counter[card]++;
        }
        
        // Iterate through the hand, forming groups of size groupSize
        for (const auto& entry : counter) {
            int value = entry.first;
            int count = entry.second;
            
            // If there are cards of this value remaining
            if (count > 0) {
                // Try to form a group starting from this value
                for (int i = 0; i < groupSize; ++i) {
                    if (counter[value + i] < count) {
                        // Not enough cards to form the group
                        return false;
                    }
                    counter[value + i] -= count;
                }
            }
        }
        
        return true;
    }
};
