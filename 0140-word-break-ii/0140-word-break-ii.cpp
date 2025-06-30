class Solution {
    unordered_map<string, bool> mp;
    vector<string> ans;
    string temp;

    void solve(int idx, string s) {
        if (idx >= s.length()) {
            temp.pop_back(); 
            ans.push_back(temp);
            return;
        }

        for (int l = 1; idx + l <= s.length(); l++) {
            string mini = s.substr(idx, l);
            if (mp[mini]) {
                int prevSize = temp.size();
                temp += mini + " ";
                solve(idx + l, s);
                temp.resize(prevSize);  
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) {
            mp[word] = true;
        }

        solve(0, s);
        return ans;
    }
};
