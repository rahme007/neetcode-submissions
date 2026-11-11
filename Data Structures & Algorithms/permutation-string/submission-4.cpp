class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s2.size() < s1.size())
            return false;

        vector<int> s1List(26,0);
        vector<int> s2List(26,0);
        int s1Len = s1.size();
        int s2Len = s2.size();
        int matches = 0;

        for (int i = 0; i < s1Len; i++) {
            s1List[s1[i] - 'a'] += 1;
            s2List[s2[i] - 'a'] += 1;
        }

        for (int i = 0; i < 26; i++) {
            if (s1List[i] == s2List[i])
                matches++;
        }

        int left = 0;

        for (int right = s1Len; right < s2Len; right++) {
            if (matches == 26)
                return true;

            int lIdx = s2[left] - 'a';
            int rIdx = s2[right] - 'a';

            s2List[lIdx] -= 1;

            if (s2List[lIdx] + 1 == s1List[lIdx])
                matches--;
            else if (s1List[lIdx] == s2List[lIdx])
                matches++;

            s2List[rIdx] += 1;

            if (s2List[rIdx] - 1 == s1List[rIdx])
                matches--;
            else if (s1List[rIdx] == s2List[rIdx])
                matches++;

            left++;

        }

        return matches == 26;
    }
};
