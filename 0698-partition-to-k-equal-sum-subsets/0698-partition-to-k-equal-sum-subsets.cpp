class Solution {
    vector<int> sum;
    int k, n,s;

    bool isEqual() {
        for (int i = 1; i < k; i++) {
            if (sum[i] != sum[0]) return false;
        }
        return true;
    }

    bool solve(vector<int>& nums, int idx) {
        if (idx >= n) {
            return isEqual();
        }

        for (int i = 0; i < k; i++) {
            if(sum[i]+nums[idx]>s)continue;
            sum[i] += nums[idx];
            if (solve(nums, idx + 1)) return true;
            sum[i] -= nums[idx];

            // Optimization: if a subset is still 0 after trying, no need to try other empty subsets
            if (sum[i] == 0) break;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0) return false;
        s=total/k;
        this->k = k;
        this->n = nums.size();
        sort(nums.rbegin(), nums.rend());  // helps in pruning
        sum = vector<int>(k, 0);

        return solve(nums, 0);
    }
};
