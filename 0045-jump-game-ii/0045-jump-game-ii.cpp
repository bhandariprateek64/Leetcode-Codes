class Solution {
    int n;
    int solve(vector<int>& nums, int idx,vector<int>&dp) {
        if (idx >= n - 1) {
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int jump = nums[idx];
        int minJumps = 1e9;
        
        for (int i = 1; i <= jump; i++) { 
            minJumps = min(minJumps, 1 + solve(nums, idx + i,dp));
        }
        
        return dp[idx]=minJumps;
    }
public:
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums, 0,dp);
    }
};
