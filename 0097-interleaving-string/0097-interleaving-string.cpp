class Solution {
    vector<vector<vector<int>>>dp;
    bool solve(string s,string t,string u,int i,int j ,int k){
        if(i==s.length() && j==t.length()  && k==u.length()  )return true;
        if(k>=u.length())return false;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(s[i]==u[k] && t[j]==u[k]){
            return dp[i][j][k]=solve(s,t,u,i+1,j,k+1) || solve(s,t,u,i,j+1,k+1);
        }else if(s[i]==u[k]){
            return dp[i][j][k]=solve(s,t,u,i+1,j,k+1);
        }else if(t[j]==u[k]){
            return dp[i][j][k]= solve(s,t,u,i,j+1,k+1);
        }else{
            return dp[i][j][k]=false;
        }

    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l=s1.length(),m=s2.length(),n=s3.length();
dp = vector<vector<vector<int>>>(l+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
     return solve(s1,s2,s3,0,0,0);
    }
};
