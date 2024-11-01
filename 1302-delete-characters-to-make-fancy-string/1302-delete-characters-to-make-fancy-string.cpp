class Solution {
public:
    string makeFancyString(string s) {
        int  n=s.size();
        if(n<3)return s;
       char c=s[0];
       char d=s[1];
       string ans="";
       ans.push_back(c);
       ans.push_back(d);
       for(int i=2;i<n;i++){
        if(s[i]==c and s[i]==d)continue;
        else{
            c=d;
            d=s[i];
            ans.push_back(s[i]);     
        }
       }
       return ans;     
    }
};