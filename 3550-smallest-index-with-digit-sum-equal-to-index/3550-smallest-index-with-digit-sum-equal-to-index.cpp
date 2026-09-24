class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++) {
            while(nums[i]>0) {
                sum=sum+nums[i]%10;
                nums[i]=nums[i]/10;
            }
            if(sum==i) return i;
            else sum=0;
        }
        return -1;
    }
};