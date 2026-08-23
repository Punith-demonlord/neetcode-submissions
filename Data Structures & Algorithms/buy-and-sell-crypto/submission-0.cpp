class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought_price=prices[0];
        int profit=0;
        for (int price:prices) {
            int curr=0;
            if (price<bought_price) {
                bought_price=price;
            } else {
                curr=price-bought_price;
            }
            profit=max(curr,profit);
        }
        return profit;
    }
};
