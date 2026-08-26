class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        for (auto c:tokens) {
            if (c=="*"||c=="-"||c=="+"||c=="/") {
                int b=eval.top();
                eval.pop();
                int a =eval.top();
                eval.pop();
                if (c=="+") {
                    a=a+b;
                }
                if (c=="-") {
                    a=a-b;
                }
                if (c=="*") {
                    a=a*b;
                }
                if (c=="/") {
                    a=a/b;
                }
                eval.push(a);
            } else {
                eval.push(stoi(c));
            }
        }
        return eval.top();
    }
};
