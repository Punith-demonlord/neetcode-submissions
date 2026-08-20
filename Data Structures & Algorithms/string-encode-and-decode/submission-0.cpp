
class Solution {
public:

    string encode(vector<string>& strs) {
        string mix="";
        for (string s:strs) {
            int k=s.size();
            mix=mix+to_string(k)+'#'+s;
        }
        return mix;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while (i<s.size()) {
            string size="";
            while (s[i]!='#') {
                size+=s[i];
                i++;
            }
            int ssize=stoi(size);
            string s1;
            
            i++;
            while (ssize!=0) {
                s1+=s[i];
                i++;
                ssize--;
            }
            res.push_back(s1);
        }
        return res;
    }
};
