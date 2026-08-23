class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxL=height[left];
        int maxR=height[right];
        int result=0;
        while (left<right) {
            if (maxL<maxR) {
                left++;
                maxL=max(maxL,height[left]);
                result+=maxL-height[left];
            } else {
                right--;
                maxR=max(maxR,height[right]);
                result+=maxR-height[right];
            }
        }
        return result;
    }
};
