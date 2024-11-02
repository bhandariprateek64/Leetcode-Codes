class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        vector<int>greater;
        int equal=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)ans.push_back(nums[i]);
            else if(nums[i]==pivot)equal++;
            else greater.push_back(nums[i]);
        }
        while(equal--){
            ans.push_back(pivot);
        }
        for(auto i : greater){
            ans.push_back(i);
        }
        return ans;
    }
};