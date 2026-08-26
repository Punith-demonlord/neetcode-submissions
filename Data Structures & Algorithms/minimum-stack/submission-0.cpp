class MinStack {
private:
    // Stores pairs of {value, current_minimum}
    vector<pair<int, int>> stacker;

public:
    MinStack() {
        // Constructor can be empty since vector is automatically initialized
    }
    
    void push(int val) {
        if (stacker.empty()) {
            stacker.push_back({val, val});
        } else {
            // Compare the new value with the previous minimum
            int current_min = min(val, stacker.back().second);
            stacker.push_back({val, current_min});
        }
    }
    
    void pop() {
        stacker.pop_back();
    }
    
    int top() {
        return stacker.back().first;
    }
    
    int getMin() {
        return stacker.back().second;
    }
};