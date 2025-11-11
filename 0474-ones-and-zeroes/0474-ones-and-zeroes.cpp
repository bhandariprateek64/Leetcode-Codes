class Solution {
    int countone(string s) {
        int ans = 0;
        for (char i : s) {
            if (i == '1') ans++;
        }
        return ans;
    }

    int solve(vector<string>& s, int m, int n, int i, vector<vector<vector<int>>>&dp) {
        if (i < 0) return 0;
        if (m < 0 || n < 0) return 0;
        if(dp[m][n][i]!=-1) return dp[m][n][i];

        int zeros = s[i].size() - countone(s[i]);
        int ones = countone(s[i]);

        if (m - zeros < 0 || n - ones < 0) return dp[m][n][i]=solve(s, m, n, i - 1,dp);

        int pick = 1 + solve(s, m - zeros, n - ones, i - 1,dp);

        int notpick = solve(s, m, n, i - 1,dp);

        return dp[m][n][i]= max(pick, notpick);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return solve(strs, m, n, strs.size() - 1,dp);
    }
};
