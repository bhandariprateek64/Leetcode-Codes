class Solution {
public:
    int smallestNumber(int n) {
        int count=0;
        while(n!=0){
            count++;
            n=n>>1;
        }
        int ans = pow(2,count)-1;
        return ans!=n ? ans : pow(2,count+1)-1;
    }
};