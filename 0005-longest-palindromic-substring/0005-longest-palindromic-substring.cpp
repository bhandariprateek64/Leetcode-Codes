class Solution {
  vector<vector<int>> dp;
bool palindrome(string &s, int i, int j) {
    if (i >= j) return true;                     // base case: length 0 or 1 → palindrome
    if (s[i] != s[j]) return false;              // mismatch → not palindrome
    if (dp[i][j] != -1) return dp[i][j];         // memoized result
    return dp[i][j] = palindrome(s, i + 1, j - 1); // check inner substring
}

public:
    string longestPalindrome(string s) {
         int n = s.length();
        dp = vector<vector<int>>(n, vector<int>(n, -1));

           int starting=0,length=1;
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(palindrome(s,i,j)){
                    if(j-i+1>length){
                        starting=i;
                        length=j-i+1;
                    }
                }
            }
        }
        return s.substr(starting, length);

    }
};
