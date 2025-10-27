class Solution {
public:
    int totalMoney(int n) {

        int ans = 0;
        int c = 0;
        for (int i = 1; i <= n; i++) {

            if (i % 7 == 0) {
                ans += 7 + c;
                c++;
            } else {
                ans += (i % 7) + c;
            }
            cout<<c<<endl;
        }
        return ans;
    }
};