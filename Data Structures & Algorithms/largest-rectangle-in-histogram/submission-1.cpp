class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> track;
        int maxArea=0;
        for (int i=0;i<heights.size();i++) {
            if (track.empty()) {
                track.push({i,heights[i]});
            } else {
                int j=i;
                
                while (!track.empty()&&heights[i]<track.top().second) {
                    int n=track.top().first;
                    int m=track.top().second;
                    maxArea=max(maxArea,(i-n)*m);
                    j=track.top().first;
                    track.pop();
                }
                track.push({j,heights[i]});
            }
        }
        while (!track.empty()) {
            int n=track.top().first;
            int m=track.top().second;
            int s=heights.size();
            maxArea=max(maxArea,(s-n)*m);
            track.pop();
        }
        return maxArea;
    }
};
