class Solution {
    vector<int>dp;
    int solve(int n){
        if(n==0)return n;
        if(n==1 or n==2) return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]= solve(n-1)+solve(n-2)+solve(n-3);
    }
public:
    int tribonacci(int n) {
        if(n==0)return n;
        if(n==1 or n==2) return 1;
        dp=vector<int>(n+1,-1);
        dp[0]=0,dp[1]=1,dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};