class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) {
            return false;
        }
        unordered_map<char,int> counta;
        for (char c:s) {
            counta[c]+=1;
        }
        for (char c:t) {
            counta[c]-=1;
        }
        for (char c:s) {
            if (counta[c]!=0) {
                return false;
            }
        }
        for (char c:t) {
            if (counta[c]!=0) {
                return false;
            }
        }
        return true;
    }
};
