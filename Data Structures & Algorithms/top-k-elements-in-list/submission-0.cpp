class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> maping;
        vector<int> res;
        for (int num:nums) {
            maping[num]+=1;
        }
        vector<vector<int>> list(nums.size()+1);
        for (auto &pair :maping) {
            list[pair.second].push_back(pair.first);
        }
        for (int j=nums.size();j>0;j--) {
            for (int num:list[j]){
                res.push_back(num);
            }
            if (res.size()==k) {
                return res;
            }
        }
        return {};
    }
};
