class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        //vector<int> count(24, 0); //O(24)
        //count[i] = how many numbers have ith bit set

        int result = 0;

        for(int i = 0; i < 24; i++) { //O(24)
            int count_ith = 0;

            for(int &num : candidates) { //O(n)
                if((num & (1 << i)) != 0) {
                    count_ith += 1;
                }
            }

            result = max(result, count_ith);

        }

        return result;
    }
};