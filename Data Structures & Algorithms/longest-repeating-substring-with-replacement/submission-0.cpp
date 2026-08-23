class Solution {
public:
    int maxAr(vector<int> &freq) {
        int max=freq[0];
        for (int num:freq) {
            if (num>max) {
                max=num;
            }
        }
        return max;
    }

    int characterReplacement(string s, int k) {
        int size=s.length();
        vector<int> freq(26,0);
        int l=0,res=0,count=0;
        for (int i=l;i<size;i++) {
            freq[s[i]-'A']+=1;
            if (i-l+1-maxAr(freq)>k) {
                freq[s[l]-'A']-=1;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};
