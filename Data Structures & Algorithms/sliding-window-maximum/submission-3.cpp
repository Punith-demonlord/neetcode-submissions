class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices, not values

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove the front element if it has slid out of the window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // 2. Remove all elements from the back that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add the current element's index to the back
            dq.push_back(i);

            // 4. Once the first window finishes forming, start recording the maximums
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};