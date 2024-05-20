'''
You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

 

Example 1:

Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.

'''

class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        count0 = 0
        count1 = 0
        
        # Count operations needed for starting with '0'
        for i in range(n):
            if i % 2 == 0:
                if s[i] != '0':
                    count0 += 1
            else:
                if s[i] != '1':
                    count0 += 1
        
        # Count operations needed for starting with '1'
        for i in range(n):
            if i % 2 == 0:
                if s[i] != '1':
                    count1 += 1
            else:
                if s[i] != '0':
                    count1 += 1
        
        return min(count0, count1)

# Callin
solution = Solution()
s = "0100"
print(solution.minOperations(s))


#--By R2