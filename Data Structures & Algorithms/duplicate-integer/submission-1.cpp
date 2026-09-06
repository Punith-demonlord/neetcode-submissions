class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> set;
        for (int i=0;i<nums.size();i++) {
            if (set.count(nums[i])){
                return true;
            } else {
                set[nums[i]]=i;
            }
        }
        return false;
    }
};