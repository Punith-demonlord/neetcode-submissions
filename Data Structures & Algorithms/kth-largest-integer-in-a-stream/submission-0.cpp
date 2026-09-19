class KthLargest {
    priority_queue<int,vector<int>,greater<int>> minheap;
    int key;
public:
    KthLargest(int k, vector<int>& nums) {
        key=k;
        for (int num:nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minheap.size()<key) {
            minheap.push(val);
        } else if (minheap.top()<val) {
            minheap.pop();
            minheap.push(val);
        } 
        return minheap.top();
    }

};
