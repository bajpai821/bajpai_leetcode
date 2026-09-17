class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> prefix_sums;
        prefix_sums[0] = -1; 
        
        vector<int> best_at_index(n, INT_MAX);
        int current_sum = 0;
        int shortest_so_far = INT_MAX;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            current_sum += arr[i];
            prefix_sums[current_sum] = i;
            
            int needed_sum = current_sum - target;
            if (prefix_sums.count(needed_sum)) {
                int start_idx = prefix_sums[needed_sum];
                int current_len = i - start_idx;
                
                shortest_so_far = min(shortest_so_far, current_len);
                
                if (start_idx >= 0 && best_at_index[start_idx] != INT_MAX) {
                    ans = min(ans, best_at_index[start_idx] + current_len);
                }
            }
            best_at_index[i] = shortest_so_far;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};