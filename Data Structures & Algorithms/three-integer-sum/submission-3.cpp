class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> res{};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0  && nums[i] == nums[i -1])
                continue;

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                
                if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left + 1 < nums.size() && nums[left] == nums[left +1])
                        left++;
                    while(right > 0 && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
