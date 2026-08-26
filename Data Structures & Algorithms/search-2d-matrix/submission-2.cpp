class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right =matrix.size()*matrix[0].size()-1;
        int middle=left+(right-left)/2;
        while (left<=right) {
            middle=left+(right-left)/2;
            int m=(middle/matrix[0].size());
            int n=middle%matrix[0].size();
            if (matrix[m][n]==target) {
                return true;
            } else if (matrix[m][n]<target) {
                left=middle+1;
            } else {
                right=middle-1;
            }
        }
        return false;

    }
};
