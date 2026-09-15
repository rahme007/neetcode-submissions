class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> cnt(nums.size()+1);
        unordered_map<int,int> umap;

        for (auto& x : nums) {
            umap[x]++; 
        }

        for (const auto& [key,value] : umap) {
            cnt[value].push_back(key);
        }
        int topK = k;
        vector<int> res;
        for (int i = cnt.size() -1; i >= 0; i--) {
            if (!cnt[i].empty()) {
                for (auto& val : cnt[i]) {
                    if (topK > 0) {
                        res.push_back(val);
                        topK--;
                    }
                }
            }
        }
        return res;
    }
};
