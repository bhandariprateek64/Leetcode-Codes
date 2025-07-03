class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a"; 
        
        while (ans.length() <= k) {
            string temp = "";
            for (char ch : ans) {
                if (ch == 'z') {
                    temp += 'a'; 
                } else {
                    temp += ch + 1;
                }
            }
            ans += temp; 
        }
        return ans[k-1]; 
    }
};
