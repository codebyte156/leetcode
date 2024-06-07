'''
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

'''

class Solution:
    def replaceWords(self, dictionary: list[str], sentence: str) -> str:
        
        dictionary.sort(key=len)
        
        
        words = sentence.split()
        
        
        def findRoot(word):
            for root in dictionary:
                if word.startswith(root):
                    return root
            return word
        
        
        replaced_words = [findRoot(word) for word in words]
        
        
        return ' '.join(replaced_words)


solution = Solution()
print(solution.replaceWords(["cat", "bat", "rat"], "the cattle was rattled by the battery"))  
print(solution.replaceWords(["a", "b", "c"], "aadsfasf absbs bbab cadsfafs"))


#By R2