class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_set<char> dup;
        int res=0;
        for (int right=0;right<s.length();right++) {
            while (dup.find(s[right])!=dup.end()) {
                dup.erase(s[left]);
                left++;
            }
            dup.insert(s[right]);
            if (res<right-left+1) {
                res=right-left+1;
            }
        }
        return res;
    }
};
