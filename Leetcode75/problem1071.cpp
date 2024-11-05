/*
GCD of the string- 
For example, we are given two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t 
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""

*/
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if str1 + str2 is equal to str2 + str1
        if (str1 + str2 != str2 + str1) {
            return "";  // No common divisor exists
        }

        // Find the GCD of the lengths of str1 and str2
        int gcdLength = std::gcd(str1.size(), str2.size());

        // The largest divisor string will be the substring of str1 with the GCD length
        return str1.substr(0, gcdLength);
    }
};