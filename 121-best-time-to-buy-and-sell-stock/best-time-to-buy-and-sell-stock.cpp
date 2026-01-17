class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxPro = 0;

        for (int i = 1; i < prices.size(); i++) {
            maxPro =max(maxPro, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return maxPro;
    }
};