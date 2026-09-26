class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Step 1: Store knowledge pairs into a hash map for O(1) lookups
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string result = "";
        string current_key = "";
        bool in_bracket = false;
        
        // Step 2: One-pass parsing over the string
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } else if (c == ')') {
                in_bracket = false;
                // Look up the extracted key in our dictionary
                if (dict.find(current_key) != dict.end()) {
                    result += dict[current_key];
                } else {
                    result += "?"; // Key not found case
                }
                current_key = ""; // Reset buffer for the next bracket pair
            } else {
                if (in_bracket) {
                    current_key += c; // Build the key
                } else {
                    result += c; // Directly append normal text
                }
            }
        }
        
        return result;
    }
};