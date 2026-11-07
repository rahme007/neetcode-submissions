class Solution {
public:
    bool checkInclusion(string s1, string s2) {


        if (s2.size() < s1.size())
            return false;
        vector<int> s1List(26,0);
        vector<int> s2List(26,0);
        int matches = 26;

        for (int i = 0; i < s1.size(); i++) {
            s1List[s1[i] - 'a'] += 1;
            s2List[s2[i] - 'a'] += 1;

        }

        for (int i = 0; i < 26; i++) {
            if (s1List[i] != s2List[i])
                matches--;
        }
        
        int left = 0, right;


        for (right = s1.size(); right < s2.size(); right++) {
            if (matches == 26)
                return true;

            int rIdx = s2[right] - 'a';
            int lIdx = s2[left] - 'a';

            s2List[rIdx] += 1;

            if (s1List[rIdx] == s2List[rIdx])
                matches++;
            else if (s1List[rIdx] + 1 == s2List[rIdx])
                matches--;

            s2List[lIdx] -= 1;

            if (s1List[lIdx] == s2List[lIdx])
                matches++;
            else if (s1List[lIdx] - 1 == s2List[lIdx])
                matches--;

            left++;
        }

        return matches == 26;
    }
};
