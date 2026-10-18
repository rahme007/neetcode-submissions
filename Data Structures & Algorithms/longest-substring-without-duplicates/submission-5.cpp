class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int longSub = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            while (umap.count(s[right])) {
                umap.erase(s[left]);
                left++;
            }
            umap[s[right]]++;
            longSub = max(longSub,right - left + 1);
            right++;
        }
        return longSub;
    }
};
