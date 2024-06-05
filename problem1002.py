'''
Given a string array words, 
return an array of all characters that show up in all strings within the words (including duplicates).
You may return the answer in any order. 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
'''

from typing import List

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        if not words:
            return []

        # Initialize a dictionary to store the frequency of characters in the first word
        char_freq = {}
        for char in words[0]:
            char_freq[char] = char_freq.get(char, 0) + 1

        # Iterate through the remaining words
        for word in words[1:]:
            # Initialize a temporary dictionary to store the frequency of characters in the current word
            temp_freq = {}
            for char in word:
                temp_freq[char] = temp_freq.get(char, 0) + 1

            # Update char_freq to contain only characters common to both char_freq and temp_freq
            for char in char_freq:
                if char in temp_freq:
                    char_freq[char] = min(char_freq[char], temp_freq[char])
                else:
                    char_freq[char] = 0

        # Construct the result list from char_freq
        result = []
        for char, freq in char_freq.items():
            result.extend([char] * freq)

        return result

# Test cases
solution = Solution()
print(solution.commonChars(["bella","label","roller"]))  # Output: ["e","l","l"]
print(solution.commonChars(["cool","lock","cook"]))     # Output: ["c","o"]


#By RR