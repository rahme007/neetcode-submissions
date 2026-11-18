class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0, right = nums.size() - 1;

        while (left < right) {

            int mid = left + ((right - left)>>1);
            if (nums[left] < nums[right]) {
                if (nums[left] <= nums[mid]) {
                    right = mid -1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[right] <= nums[mid])
                    left = mid + 1;
                else 
                    right = mid;
            }


        }
            return nums[left];
        
    }
};
