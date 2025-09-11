#include <algorithm>

class Solution {
private:
    bool isvowel(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U');
    }

public:
    string sortVowels(string s) {
        string ans;

        for (int i = 0; i < s.length(); i++) {
            if (!isvowel(s[i])) {
                ans += s[i];
            } else {
                ans += ' ';
            }
        }

        string vowels;
        for (int i = 0; i < s.length(); i++) {
            if (isvowel(s[i])) {
                vowels += s[i];
            }
        }

        sort(vowels.begin(), vowels.end());

        int vowelIndex = 0;
        for (int i = 0; i < ans.length(); i++) {
            if (ans[i] == ' ') {
                ans[i] = vowels[vowelIndex++];
            }
        }

        return ans;
    }
};
