class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size()) {
            return findMedianSortedArrays(nums2,nums1);
        } 
        int total=nums1.size()+nums2.size();
        int half=total/2;
        int l=0;
        int r=nums1.size()-1;
        while (true) {
            int i=floor((r+l)/2.0);
            int j=half-i-2;
            int aleft=(i<0)?INT_MIN:nums1[i];
            int aright=(i+1>=nums1.size())?INT_MAX:nums1[i+1];
            int bleft=(j<0)?INT_MIN:nums2[j];
            int bright=(j+1>=nums2.size())?INT_MAX:nums2[j+1];
            if (aleft<=bright&&aright>=bleft) {
                return total%2==0?double((min(aright,bright)+max(aleft,bleft))/2.0):double(min(bright,aright));
            } else if (aleft>bright) {
                r=i-1;
            } else {
                l=i+1;
            }
        }
        return 1.3;
    }
};
