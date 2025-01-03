class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int d1 = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - prices[d1] > 0) res = max(res, prices[i] - prices[d1]);
            else d1 = i;
        }
        return res;
    }
};
