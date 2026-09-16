class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int sum=0;
        int sum2=0;
        for(int i=0; i<n; i++) {
            if(colors[i] != colors[n-1]) {
                sum=n-i-1;
                break;
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(colors[0] != colors[i]) {
                sum2=i;
                break;
            }
        }
        
        return max(sum, sum2);
        
    }
};