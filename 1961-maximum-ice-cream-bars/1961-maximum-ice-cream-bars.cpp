class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count[100001] = {0};
        int ans = 0;
        
        for(int i = 0 ; i < costs.size(); i++){
            count[costs[i]]++;
        }

        for(int i = 1; i <= 100000; i++){
            if(count[i] > 0){
                while(count[i] > 0 && coins > 0){
                    ans += 1;
                    coins -= i;
                    count[i]--;
                }
                if(coins == 0)
                    return ans;
                if(coins < 0)
                    return ans - 1;
            }
        }
        return ans;
    }
};