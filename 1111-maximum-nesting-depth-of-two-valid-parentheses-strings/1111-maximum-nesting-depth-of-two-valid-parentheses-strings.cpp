#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> ans;
        ans.reserve(seq.size());
        int current_depth = 0;

        for (char c : seq) {
            if (c == '(') {
                current_depth++;
                // Distribute evenly using parity (even/odd)
                ans.push_back(current_depth % 2); 
            } else {
                // For closing, use current depth before decrementing
                ans.push_back(current_depth % 2);
                current_depth--;
            }
        }
        
        return ans;
    }
};
