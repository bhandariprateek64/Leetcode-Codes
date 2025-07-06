class Solution {
    vector<int> dp;
    int solve(string& s, int i) {
        if (i < 0)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        if (s[i] == '0') {
            if (i - 1 >= 0 && (s[i - 1] == '1' || s[i - 1] == '2')) {
                return solve(s, i - 2);
            } else {
                return 0;
            }
        }
        int pickOne = solve(s, i - 1);
        int pickTwo = 0;
        if (i - 1 >= 0) {
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26)
                pickTwo = solve(s, i - 2);
        }
        return dp[i] = pickOne + pickTwo;
    }

public:
    int numDecodings(string s) {
        int n = s.length();
        dp = vector<int>(n, -1);
        return solve(s, n - 1);
    }
};
