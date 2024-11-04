class Solution {
public:
    string compressedString(string s) {
        if (s.empty()) return ""; 

        int count = 1;
        string comp = "";

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else {
               
                while (count > 9) {
                    comp += "9";
                    comp += s[i];
                    count -= 9;
                }
                comp += to_string(count); 
                comp += s[i];
                count = 1; 
            }
        }

   
        while (count > 9) {
            comp += "9";
            comp += s.back();
            count -= 9;
        }
        comp += to_string(count);
        comp += s.back(); 

        return comp;
    }
};
