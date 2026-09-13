class Solution {
public:

    string encode(vector<string>& strs) {
        int sz;
        string enStr = "";
        for (auto& s : strs) {
            sz = s.size();
            enStr += to_string(sz) + "#" + s;
        }
        return enStr;

    }

    vector<string> decode(string s) {
        int idx = 0;
        vector<string> res;
        while (idx < s.size()) {
            int strSz = 0;
            if (s[idx] == '0') {
                res.push_back("");
                idx += 2;
                continue;
            }

            while (s[idx] != '#') {
                strSz = 10 *strSz + (s[idx] - '0');
                idx++; 
            }
            idx++;
            res.push_back(s.substr(idx,strSz));
            idx = idx+strSz;
        }

        return res;
    }
};
