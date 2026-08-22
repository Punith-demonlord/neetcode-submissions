class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lista(nums.begin(),nums.end());
        int count=0,longest=0;
        for (int num:lista) {
            if (lista.find(num-1)==lista.end()) {
                count=1;
                int currentNum=num;
                while (lista.find(currentNum+1)!=lista.end()) {
                currentNum+=1;
                count++;
            }
            } else {continue;}
            
            if (longest<count) {
                longest=count;
            }
        }
        return longest;
    }
};
