class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces
        int left = 0, right = s.length() - 1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        // Collect words in reverse order
        string result, word;
        for (int i = right; i >= left; i--) {
            if (s[i] != ' ') {
                word.push_back(s[i]);
            } else if (!word.empty()) {
                reverse(word.begin(), word.end());
                result += word + ' ';
                word.clear();
            }
        }
        // Add the last word (if any)
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            result += word;
        }

        // Remove the trailing space
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
