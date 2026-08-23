class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxL;
        int max=0;
        for (int num :height) {
            if (num>max) {max=num;}
            maxL.push_back(max);
        }
        vector<int> maxR(height.size());
        max=0;
        for (int i=height.size()-1;i>=0;i--) {
            if (height[i]>max) {max=height[i];}
            maxR[i]=max;
        }
        int result=0;
        for (int i=0;i<height.size();i++) {
            if (min(maxL[i],maxR[i])-height[i]>0) {
                result+=min(maxL[i],maxR[i])-height[i];
            }
        }
        return result;
    }
};
