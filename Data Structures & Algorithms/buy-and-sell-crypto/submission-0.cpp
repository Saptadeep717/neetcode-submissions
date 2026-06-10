class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0,mp=0,prevBought=prices[0];

        for(int i=1;i<n;i++){
            profit = prices[i] - prevBought;
            mp = max(profit,mp);
            prevBought = min(prevBought, prices[i]);
        }
        return mp;
    }
};
