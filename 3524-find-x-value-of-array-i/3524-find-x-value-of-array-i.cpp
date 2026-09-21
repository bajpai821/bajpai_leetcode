class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> new_dp(k, 0);
            int num_mod = num % k;
            
            
            new_dp[num_mod] += 1;
            
           
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_mod = (r * num_mod) % k;
                    new_dp[new_mod] += dp[r];
                }
            }
            
           
            for (int r = 0; r < k; ++r) {
                result[r] += new_dp[r];
            }
            dp = std::move(new_dp);
        }
        return result;
    }
};
