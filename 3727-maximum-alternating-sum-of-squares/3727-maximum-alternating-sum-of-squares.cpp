#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxAlternatingSum(std::vector<int>& nums) {
        int n = nums.size();
        
        // Square all the elements first to sort by their squared values
        for (int& x : nums) {
            x = x * x;
        }
        
        // Sort the squared values in ascending order
        std::sort(nums.begin(), nums.end());
        
        long long ans = 0;
        int m = n / 2; // Number of elements that will be subtracted
        
        // The first half (smaller squares) gets subtracted
        for (int i = 0; i < m; ++i) {
            ans -= nums[i];
        }
        
        // The second half (larger squares) gets added
        for (int i = m; i < n; ++i) {
            ans += nums[i];
        }
        
        return ans;
    }
};
