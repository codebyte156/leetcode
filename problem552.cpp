/*
An attendance record for a student can be represented as a string where each 
character signifies whether the student was absent, late, or present on that day. 
The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. 
The answer may be very large, so return it modulo 109 + 7.
*/



#include <vector>

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        //DP table
        std::vector<std::vector<std::vector<long long>>> dp(n + 1, std::vector<std::vector<long long>>(2, std::vector<long long>(3, 0)));
        
        //Base case
        dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            //Calculate rec ending with 'P'
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][1][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2] + dp[i][0][0]) % MOD;
            
            // Calculate rec ending with 'L'
            dp[i][0][1] = dp[i - 1][0][0];
            dp[i][1][1] = dp[i - 1][1][0];
            
            // Calculate rec ending with 'LL'
            dp[i][0][2] = dp[i - 1][0][1];
            dp[i][1][2] = dp[i - 1][1][1];
        }
        
        // Calculate tot number of valid records
        long long total = 0;
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                total = (total + dp[n][j][k]) % MOD;
            }
        }
        
        return static_cast<int>(total);
    }
};


//By R2
