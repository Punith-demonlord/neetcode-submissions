class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for (int i=0;i<nums.size()-2;i++) {
            int start =i+1;
            int end=nums.size()-1;
            if (i>0&&nums[i-1]==nums[i]) {
                continue;
            }
            while (start<end) {
                
                if (nums[start]+nums[end]==-nums[i]) {
                    result.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while (start<end&&nums[start]==nums[start-1]) {start++;}
                while (start<end&&nums[end]==nums[end+1]) {end--;}
                } else if(nums[start]+nums[end]+nums[i]<0){
                    start++;
                } else if(nums[start]+nums[end]+nums[i]>0){
                    end--;
                } 
            }
        } 
        return result;
    }
};
