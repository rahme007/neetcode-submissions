class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxArea = 0;

        while (left < right) {

            int minHgt = min(heights[left] , heights[right]);
            int area = minHgt * (right - left);
            maxArea = max(area,maxArea);

            if (heights[left] == heights[right])
                left++;
            else if (minHgt == heights[left])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
