class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size(), res = 0;
        for(int i = 0; i < m; ++i) sort(nums[i].begin() , nums[i].end());
        for(int j = 0, n = nums[0].size(); j < n; ++j){
            int maxi = 0;
            for(int i = 0; i < m; ++i) maxi = max(maxi , nums[i][j]);
            res += maxi;
        }
        return res;
    }
};