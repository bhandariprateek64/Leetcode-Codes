class Solution {
public:
    int Leftsolve(vector<int>&nums,int i,int pre,vector<vector<int>>&dpleft){
        if(i==-1){return 0;}
        int pick=0;
        if(dpleft[i][pre]!=-1)return dpleft[i][pre];
        if(nums[i]<nums[pre]){
            pick=1+Leftsolve(nums,i-1,i,dpleft);
        }
        int notpick=Leftsolve(nums,i-1,pre,dpleft);
        return dpleft[i][pre]=max(pick,notpick);
    }
    int rightsolve(vector<int>&nums,int i,int pre,vector<vector<int>>&dpright){
        if(i==nums.size())return 0;
        int pick=0;
        if(dpright[i][pre]!=-1)return dpright[i][pre];
        if(nums[i]<nums[pre]){
            pick=1+rightsolve(nums,i+1,i,dpright);
        }
        int notpick=rightsolve(nums,i+1,pre,dpright);
        return dpright[i][pre]=max(pick,notpick);
    }
    int minimumMountainRemovals(vector<int>& nums) {

        int n=nums.size();
        int ans=n;
        vector<vector<int>>dpleft(n,vector<int>(n,-1));
        vector<vector<int>>dpright(n,vector<int>(n,-1));
       
        for(int i=1;i<n-1;i++){
            
            int left=Leftsolve(nums,i-1,i,dpleft);  
          
            int right=rightsolve(nums,i+1,i,dpright); 
            //left ans right both should at least one
            if(left&&right)ans=min(ans,n-(left+right+1));
        }
        return ans;
        
    }
};