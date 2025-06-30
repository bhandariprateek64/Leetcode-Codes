class Solution {
    unordered_map<string,bool>mp;
     vector<int>dp;
    bool solve(int idx,string s){
        if(idx>=s.length())return true;
        if(dp[idx]!=-1)return dp[idx];
        for(int l=1;idx+l<=s.length();l++){
            string mini=s.substr(idx,l);
            if(mp[mini] && solve(idx+l,s))return true;
        }
        return dp[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word: wordDict){
            mp[word]=true;
        }   
       dp= vector<int>(s.length()+1,-1);
        return solve(0,s);
    }
};