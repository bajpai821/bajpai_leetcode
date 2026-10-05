class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                // Increase nesting depth
                ++depth;
            } else {
                // Decrease nesting depth
                --depth;
                
                // If it's a primitive "()" pair, calculate its contribution
                if (s[i - 1] == '(') {
                    ans += (1 << depth); // equivalent to 2^depth
                }
            }
        }
        
        return ans;
    }
};
