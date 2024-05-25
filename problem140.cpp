/*

Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]

*/


#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(s.size() + 1, vector<string>());

        dp[0] = {""};

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string word = s.substr(j, i - j);
                if (dict.find(word) != dict.end()) {
                    for (const string& prev : dp[j]) {
                        dp[i].push_back(prev + (prev.empty() ? "" : " ") + word);
                    }
                }
            }
        }

        return dp[s.size()];
    }
};


//Coded by R2

