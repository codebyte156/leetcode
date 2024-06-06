#include <string>
#include <vector>

class Solution {
public:
    std::string shiftingLetters(std::string s, std::vector<int>& shifts) {
        int n = s.size();
        
        // Calculate cumulative shifts
        long long cumulativeShifts = 0;
        for (int i = n - 1; i >= 0; --i) {
            cumulativeShifts = (cumulativeShifts + shifts[i]) % 26; // Take modulo to handle large shifts
            s[i] = shiftChar(s[i], cumulativeShifts);
        }
        
        return s;
    }
    
    char shiftChar(char c, long long shifts) {
        // Shift character 'c' by 'shifts' positions
        return 'a' + (c - 'a' + shifts) % 26;
    }
};
