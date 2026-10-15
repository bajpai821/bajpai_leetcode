class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) {
            std::unordered_set<int> s;
            for(int j=i; j<n; j++) {
                s.insert(nums[j]);

                sum+=(s.size()*s.size());
            }
            
        }
        return sum;
    }
};