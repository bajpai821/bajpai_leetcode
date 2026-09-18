class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        
        
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            leftmost[idx] = min(leftmost[idx], i);
            rightmost[idx] = i;
        }
        
        vector<string> ans;
        int last_valid_end = -1;
        
       
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            
           
            if (i != leftmost[idx]) continue;
            
            int current_end = rightmost[idx];
            bool is_valid = true;
            
           
            for (int j = i; j <= current_end; ++j) {
                int inner_idx = s[j] - 'a';
                
               
                if (leftmost[inner_idx] < i) {
                    is_valid = false;
                    break;
                }
              
                current_end = max(current_end, rightmost[inner_idx]);
            }
            
            if (!is_valid) continue;
            
         
            if (current_end <= last_valid_end) {
                ans.pop_back();
            }
            
            ans.push_back(s.substr(i, current_end - i + 1));
            last_valid_end = current_end;
        }
        
        return ans;
    }
};