class Solution {
int n;
bool solve(vector<int>& nums, int idx,vector<int>&dp) {
    if (idx >= n - 1) return true;  
    if (dp[idx] != -1) return dp[idx];
    int jump = nums[idx];
    for (int i = 1; i <= jump; i++) { 
        if (solve(nums, idx + i,dp)) {    
            return dp[idx]= true;        
        }
    }

    return dp[idx]=false;                
}
public:
    bool canJump(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);

    }
};