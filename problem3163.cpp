/*
3163. String Compression III - Medium Level
Given a string word, compress it using the following algorithm:
Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.
*/


#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string comp = ""; //adding a space in it caused an error in the output
        int n = word.length();
        int i = 0;
        
        while (i < n) {
            char c = word[i];
            int count = 0;
            while (i < n && word[i] == c && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + c;
        }
        return comp;
    }
};
