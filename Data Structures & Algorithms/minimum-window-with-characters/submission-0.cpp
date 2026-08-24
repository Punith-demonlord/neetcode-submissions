class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        
        vector<int> match(128, 0);
        int need = 0;
        
        // 1. Build the target map and count UNIQUE characters for 'need'
        for (int i = 0; i < t.length(); i++) {
            if (match[t[i]] == 0) {
                need++; 
            }
            match[t[i]]++;
        }
        
        vector<int> window(128, 0);
        int have = 0, l = 0;
        
        // Use discrete variables to track the best result safely
        int res_start = -1;
        int res_len = INT_MAX;
        
        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;
            
            if (match[c] > 0 && window[c] == match[c]) {
                have++;
            }
            
            while (have == need) {
                // Update minimum result bounds
                if (r - l + 1 < res_len) {
                    res_start = l;
                    res_len = r - l + 1;
                }
                
                // Shrink window from the left
                char left_char = s[l];
                window[left_char]--;
                
                // Only decrement 'have' if the count falls below what we need
                if (match[left_char] > 0 && window[left_char] < match[left_char]) {
                    have--;
                }
                l++;
            }
        }
        
        // Use C++ substr: starting index, length
        if (res_len == INT_MAX) {
            return "";
        } else {
            return s.substr(res_start, res_len);
        }
    }
};