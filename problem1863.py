'''
The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6


'''
from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        def backtrack(index, path_xor):
            nonlocal total_xor
            total_xor += path_xor
            for i in range(index, len(nums)):
                backtrack(i + 1, path_xor ^ nums[i])

        total_xor = 0
        backtrack(0, 0)
        return total_xor

# Calling XD
solution = Solution()
nums = [1, 3]
print(solution.subsetXORSum(nums))


#--By CodeByte156