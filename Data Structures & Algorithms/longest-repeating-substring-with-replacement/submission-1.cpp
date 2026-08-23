class Solution {
public:

    int characterReplacement(string s, int k) {
        int size=s.length();
        vector<int> freq(26,0);
        int l=0,res=0,max_freq=0;
        for (int i=l;i<size;i++) {
            freq[s[i]-'A']+=1;
            max_freq=max(max_freq,freq[s[i]-'A']);
            if (i-l+1-max_freq>k) {
                freq[s[l]-'A']-=1;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};
