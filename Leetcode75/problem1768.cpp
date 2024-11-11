#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;

        // Alternate characters from each string
        while (i < word1.size() && j < word2.size()) {
            result += word1[i++];
            result += word2[j++];
        }

        // Append any remaining characters from word 1
        while (i < word1.size()) {
            result += word1[i++];
        }
        
        // Append any remaining characters from word 2
        while (j < word2.size()) {
            result += word2[j++];
        }
        
        return result;
    }
};
