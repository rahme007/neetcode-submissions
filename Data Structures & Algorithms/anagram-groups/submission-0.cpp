class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        vector<int> cnt;


        for (auto& str : strs) {
            vector<int> cnt(26,0);

            for (auto& s : str) {
                cnt[s - 'a'] += 1;
            }

            string key = to_string(cnt[0]);

            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(cnt[i]);
            }
            umap[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto& [key,value] : umap) {
            res.push_back(value);
        }

        return res;
    }
};
