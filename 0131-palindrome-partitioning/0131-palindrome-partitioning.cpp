class Solution {
    int n;
    vector<vector<string>> ans;
    vector<string> temp;

    bool isPal(const string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void solve(string &s, int idx) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < n; ++i) {
            string current = s.substr(idx, i - idx + 1);
            if (isPal(current)) {
                temp.push_back(current);
                solve(s, i + 1);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        ans.clear();
        temp.clear();
        solve(s, 0);
        return ans;
    }
};
