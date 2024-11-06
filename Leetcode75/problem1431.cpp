#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies any kid currently has
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        // Initialize a result vector to store the answer
        vector<bool> result;
        
        // For each kid, check if they would have the greatest number of candies
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }
        
        return result;
    }
};
