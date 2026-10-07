#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::vector<int> result;
        
        for (int num : nums2) {
            // If the element is found, add to result and remove from set to handle duplicates
            if (set1.erase(num)) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};
