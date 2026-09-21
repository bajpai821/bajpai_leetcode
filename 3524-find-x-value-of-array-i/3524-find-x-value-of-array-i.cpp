class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<long long> result(k, 0);
        long long dp[5] = {0};
        long long next_dp[5] = {0};
        
        for (int num : nums) {
            int num_mod = num % k;
            
           
            for (int r = 0; r < k; ++r) {
                next_dp[r] = 0;
            }
            
           
            next_dp[num_mod] += 1;
            
           
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_mod = (r * num_mod) % k;
                    next_dp[new_mod] += dp[r];
                }
            }
            
            
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
                dp[r] = next_dp[r];
            }
        }
        return result;
    }
};
