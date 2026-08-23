class Solution {
public:
    int maxArea(vector<int>& heights) {
        int vol=0;
        int left=0;
        int right=heights.size()-1;
        int width=0;
        int curr=0;
        while (left<right) {
            width=right-left;
            curr=width*min(heights[left],heights[right]);
            if (curr>vol) {
                vol=curr;
            }
            if (heights[left]>heights[right]) {
                right--;
            } else {
                left++;
            }
        }
        return vol;
    }
};
