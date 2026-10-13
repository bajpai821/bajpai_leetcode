class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        for(int i=0; i<nums1.size(); i++) {
            if(nums1[i]==nums2[nums2.size()-1]) {
                output.push_back(-1);
                continue;
            }
            for(int j=0; j<nums2.size()-1; j++) {
                if(nums1[i]==nums2[j]) {
                    for(int k=j+1; k<nums2.size(); k++) {
                        if(nums2[k]>nums2[j]) {
                            output.push_back(nums2[k]);
                            break;
                        }
                        if(k==nums2.size()-1) output.push_back(-1);
                    }
                    break;
                }
            }
        }
        return output;
    }
};