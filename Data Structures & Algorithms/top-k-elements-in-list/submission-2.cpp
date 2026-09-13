class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for (auto& x : nums) {
            umap[x] += 1;
        }
        vector<vector<int>>arr(nums.size()+1);
        vector<int> res;

        for (auto& [key,value] : umap) {
            arr[value].push_back(key);
        }
        int topEl = k;

        for (int j = arr.size()-1; j>= 0; j--) {
            if (!arr[j].empty() && topEl > 0) {
                for (auto& y : arr[j]) {
                    if (topEl > 0) {
                        res.push_back(y);
                        topEl--;
                    }

                }

            }
        }
        return res;
    }
};
