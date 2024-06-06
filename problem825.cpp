#include <vector>
#include <unordered_map>

class Solution {
public:
    int numFriendRequests(std::vector<int>& ages) {
        std::unordered_map<int, int> ageCounts;
        for (int age : ages) {
            ageCounts[age]++;
        }
        
        // int requests = 0;
        // for (const auto& [ageX, countX] : ageCounts) {
        //     for (const auto& [ageY, countY] : ageCounts) {
        //         if (isValidRequest(ageX, ageY)) {
        //             requests += countX * (countY - (ageX == ageY ? 1 : 0));
        //         }
        //     }
        // }
        
        //return requests;
    }
    
    bool isValidRequest(int ageX, int ageY) {
        return !(ageY <= 0.5 * ageX + 7 || ageY > ageX || (ageY > 100 && ageX < 100));
    }
};
