class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size() , col = matrix[0].size();
        int left = 0, right = row * col - 1;

        while (left <= right) {
            int mid = left + ((right - left)>>1);
            int r = mid /col ;
            int c = (mid % col);

            if (matrix[r][c] < target) {
                left = mid + 1;
            }
            else if (matrix[r][c] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};
