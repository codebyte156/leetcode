/*

Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

 

Example 1:

Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.

*/


#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCount(26, 0);
        for (char letter : letters) {
            ++letterCount[letter - 'a'];
        }
        return backtrack(0, words, letterCount, score);
    }

private:
    int backtrack(int index, vector<string>& words, vector<int>& letterCount, vector<int>& score) {
        if (index == words.size()) return 0; // Base case: no more words left

        // Calculate score if word at current index is not included
        int scoreWithoutWord = backtrack(index + 1, words, letterCount, score);

        // Check if the word at current index can be formed using available letters
        bool canFormWord = true;
        vector<int> letterCountCopy = letterCount;
        int wordScore = 0;
        for (char letter : words[index]) {
            if (letterCountCopy[letter - 'a'] == 0) {
                canFormWord = false;
                break;
            } else {
                --letterCountCopy[letter - 'a'];
                wordScore += score[letter - 'a'];
            }
        }

        // If the word can be formed, recursively calculate the score with and without including the word
        int scoreWithWord = 0;
        if (canFormWord) {
            scoreWithWord = wordScore + backtrack(index + 1, words, letterCountCopy, score);
        }

        // Return the maximum score obtained by including or excluding the word
        return max(scoreWithWord, scoreWithoutWord);
    }
};


// Coded by R2

