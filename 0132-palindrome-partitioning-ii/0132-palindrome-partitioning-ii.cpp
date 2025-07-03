class Solution {
    int n;
    vector<int> dp;
    bool isPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int minCuts(const string &s, int idx) {
        if (idx == n) return -1;  
        if (dp[idx] != -1) return dp[idx];

        int res = INT_MAX;
        for (int i = idx; i < n; ++i) {
            if (isPalindrome(s, idx, i)) {
                int cuts = 1 + minCuts(s, i + 1); 
                res = min(res, cuts);
            }
        }

        return dp[idx] = res;
    }

public:
    int minCut(string s) {
        n = s.size();
        dp.assign(n, -1);
        return minCuts(s, 0);
    }
};
