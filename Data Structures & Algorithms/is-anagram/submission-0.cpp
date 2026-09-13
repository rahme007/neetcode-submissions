class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;
        unordered_map<char,int> mapS;
        unordered_map<char,int> mapT;

        for (int i = 0; i < s.size(); i++) {
            mapS[s[i]] += 1;
            mapT[t[i]] += 1;
        }
        for (auto& [key,value] : mapS) {
            if (mapS[key] != mapT[key])
                return false;
        }
        return true;
    }
};
