'''
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
'''

class Solution:
    def numSteps(self, s: str) -> int:
        steps = 0
        num = int(s, 2)
        
        while num != 1:
            if num % 2 == 0:
                num //= 2
            else:
                num += 1
            steps += 1
        
        return steps

#By RR