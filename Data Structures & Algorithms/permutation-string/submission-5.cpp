class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) {
            return false;
        }
        vector<int> match(26,0);
        vector<int> winmatch(26,0);
        for (int i=0;i<s1.size();i++) {
            match[s1[i]-'a']+=1;
            winmatch[s2[i]-'a']+=1;
        }
        for (int i=s1.length();i<s2.length();i++) {
            if (match==winmatch) {
                return true;
            }
            winmatch[s2[i]-'a']+=1;
            winmatch[s2[(i-s1.length())]-'a']--;
        }
        return match==winmatch;
    }
};
