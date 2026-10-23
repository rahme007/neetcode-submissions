class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        
        vector<int> cntS1(26,0);
        vector<int> cntS2(26,0);


        int left = 0,right = 0;

        for (int i = 0; i < s1.size(); i++) {
            cntS1[s1[i] - 'a'] += 1;
            cntS2[s2[i] - 'a'] += 1;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (cntS1[i] == cntS2[i])
                matches++;
        }
        right += s1.size();
        while (right < s2.size()) {
            if (matches == 26)
                return true;

            
            int index = s2[left] - 'a';
            cntS2[index]--;

            if (cntS1[index] == cntS2[index])
                matches++;
            else if (cntS1[index] == cntS2[index] + 1)
                matches--;

            index = s2[right] - 'a';
            cntS2[index] += 1;
            
            if (cntS1[index] == cntS2[index])
                matches++;
            else if (cntS1[index] == cntS2[index] - 1)
                matches--;

            left++;
            right++;


        }

        return matches == 26;
    }
};
