class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for (string s:strs) {
            string k=s;
            sort(k.begin(),k.end());
            res[k].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &pair:res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
