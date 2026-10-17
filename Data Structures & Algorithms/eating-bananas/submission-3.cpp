class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        
        int left = 1, right = piles[piles.size() - 1];
        
        int minH = h;
        int mid;
        while (left <= right) {

            long long total = 0;
            mid = right + ((left - right)>> 1);
            for (int i = 0; i < piles.size(); i++) {
                total += (piles[i] / mid) + 
                ((piles[i] % mid > 0) ? 1 : 0); 
            }
            if (total > minH)
                left = mid + 1;
            else {
                right = mid - 1;
                //minH = min(minH, total);
            }

        }
        return left;
    }
};
