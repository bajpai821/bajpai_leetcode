class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector <int>ans(n);
        int left=0;
        int right=n-1;
        int index=n-1;

        while(left<=right) {
            int lsq=nums[left]*nums[left];
            int rsq=nums[right]*nums[right];

            if(lsq>rsq) {
                ans[index]=lsq;
                left++;
            } else {
                ans[index]=rsq;
                right--;
            }
            index--;
        }
        return ans;
        
    }
};