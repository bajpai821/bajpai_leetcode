class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int current_depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                current_depth++;
                // Har baar check karein ki kya yeh ab tak ki maximum depth hai
                max_depth = max(max_depth, current_depth);
            } 
            else if (c == ')') {
                current_depth--;
            }
        }
        
        return max_depth;
    }
};
