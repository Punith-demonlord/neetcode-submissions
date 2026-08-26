class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> check;
        for (int i=0;i<temperatures.size();i++) {
            while (!check.empty()&&temperatures[check.top()]<temperatures[i]) {
                result[check.top()]=i-check.top();
                check.pop();
                
            }
            check.push(i);
            
        }
        
        return result;
    }
};
