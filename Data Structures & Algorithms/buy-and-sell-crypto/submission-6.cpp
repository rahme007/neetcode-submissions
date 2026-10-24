class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;
        int left = 0, right = 1;
        int maxProfit = 0;

        while (right < prices.size()) {
            while (prices[left] > prices[right])
                left++;
            
            maxProfit = max(maxProfit, prices[right] -
            prices[left]);
            right++;
        }
        return maxProfit;
    }
};
