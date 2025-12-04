class Solution {
public:
    int minimumFlips(int n) {
        string ans="";
        while(n>0){
            ans= (char)(n%2)+ans;
            n=n>>1;
        }
        string t =ans;
        int count=0;
        reverse(t.begin(),t.end());
        for(int i=0;i<t.size();i++){
            if(ans[i]!=t[i])count++;
        }
        return count;
    }
};