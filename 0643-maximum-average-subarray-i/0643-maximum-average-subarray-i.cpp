class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double csum=0;
        for(int i=0; i<k; i++) {
            csum = csum + nums[i];
        }
        double msum=csum;
        for(int i=k; i<n; i++) {
            csum=csum+nums[i]-nums[i-k];
            if(csum > msum) {
                msum=csum;
            }
        } 
        return msum/k;
    }
};