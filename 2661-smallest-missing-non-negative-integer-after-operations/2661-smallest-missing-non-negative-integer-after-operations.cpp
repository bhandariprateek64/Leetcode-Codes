class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>freq;
        for(int i:nums){
            if(i<0)freq[((i%value)+value)%value]++;
            else freq[i%value]++;
        }
        int i=0;
        while(true){
            if(freq[i%value]==0)return i;
            else freq[i%value]--;
            i++;
        }     
        return 0;
    }
};