class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> startproduct(nums.size(),1);
        vector<int> endproduct(nums.size(),1);
        vector<int> result(nums.size(),1); 
        int val=1,va=1;
        for (int i=1;i<nums.size();i++) {
            val*=nums[i-1];
            startproduct[i]=val;
        }
        for (int j=nums.size()-1;j>0;j--) {
            va=va*nums[j];
            endproduct[j-1]=va;
        }
        for (int i=0;i<nums.size();i++) {
            result[i]=startproduct[i]*endproduct[i];
        }
        return result;
    }
};
