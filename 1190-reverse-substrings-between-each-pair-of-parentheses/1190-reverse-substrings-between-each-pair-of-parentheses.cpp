class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> openBrackets;
        std::string result = "";
        
        for (char c : s) {
            if (c == '(') {
                // Store the current length of the result string 
                // which marks the start index of this nested block
                openBrackets.push(result.length());
            } 
            else if (c == ')') {
                // Get the start position of the matching '('
                int startIdx = openBrackets.top();
                openBrackets.pop();
                
                // Reverse the substring from that start position to the end
                std::reverse(result.begin() + startIdx, result.end());
            } 
            else {
                // Append normal characters to the resulting string
                result += c;
            }
        }
        
        return result;
    }
};