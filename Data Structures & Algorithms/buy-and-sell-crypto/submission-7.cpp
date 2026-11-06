class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0;
        int maxProfit = 0;

        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                maxProfit = max(prices[right] - prices[left], maxProfit);
            }
            else {
                left = right;
            }

            right++;
        }
        return maxProfit;
    }
};
