class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;

        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.size()) {


            if (umap.count(s[right])) {
                while (umap.count(s[right])) {
                    umap.erase(s[left]);
                    left++;
                }
            }
            maxLen = max(maxLen, right -left + 1);
            umap[s[right]] += 1;
            right++;
        }
        return maxLen;
    }
};
