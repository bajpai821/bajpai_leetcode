class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        long long sum = 0; // Use long long to avoid 32-bit integer overflow
        
        for (int num : nums) {
            sum += num;
            min_val = min(min_val, num);
        }
        
        return sum - (long long)min_val * nums.size();
    }
};
