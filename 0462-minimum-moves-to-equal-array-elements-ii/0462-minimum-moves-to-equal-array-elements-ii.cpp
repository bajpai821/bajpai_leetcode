#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minMoves2(std::vector<int>& nums) {
        // Step 1: Sort the array to find the median
        std::sort(nums.begin(), nums.end());
        
        // Step 2: Identify the median element
        int median = nums[nums.size() / 2];
        
        int moves = 0;
        // Step 3: Accumulate the total steps required
        for (int num : nums) {
            moves += std::abs(num - median);
        }
        
        return moves;
    }
};
