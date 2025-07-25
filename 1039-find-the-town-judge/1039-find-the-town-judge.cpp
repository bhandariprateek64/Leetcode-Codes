class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>vis(n+1,0),incoming(n+1,0);
        for(auto t:trust){
            vis[t[0]]=1;
            incoming[t[1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(vis[i]==0 and incoming[i]==n-1)return i;
        }
        return -1;
    }
};