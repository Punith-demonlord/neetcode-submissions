class Solution {
public:
    bool isValid(string s) {
        stack<char> match;
        for (char c:s) {
            if (c=='{'||c=='('||c=='[') {
                match.push(c);
            } else {
                if (match.empty()) {
                    return false;
                }
                char temp=c;
                char temper=match.top();
                match.pop();
                if (temp=='}'&&temper!='{') {
                    return false;
                }
                if (temp==')'&&temper!='(') {
                    return false;
                }
                if (temp==']'&&temper!='[') {
                    return false;
                }
                
            }

        }
        return match.empty();
    }
};
