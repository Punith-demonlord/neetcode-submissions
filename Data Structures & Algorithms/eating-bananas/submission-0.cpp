class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxp=INT_MIN;
        for (int i=0;i<piles.size();i++) {
            if (maxp<piles[i]) {
                maxp=piles[i];
            }
        }
        int l=1;
        int r=maxp;
        int res=maxp;
        int mid=(l+r)/2;
        while (l<=r) {
            mid=(l+r)/2;
            int count=0;
            for (int num:piles) {
                count+=ceil((double)num/mid);
            }
            if (count<=h) {
                res=min(res,mid);
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return res;
    }
};
