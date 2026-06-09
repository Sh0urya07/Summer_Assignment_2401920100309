class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (p.length() > s.length()) {
            return result;
        }
        int countP[26] = {0};
        int countS[26] = {0};
        for (int i = 0; i < p.length(); i++) {
            countP[p[i] - 'a']++;
            countS[s[i] - 'a']++;
        }
        if (equal(countP, countP + 26, countS)) {
            result.push_back(0);
        }
        for (int i = p.length(); i < s.length(); i++) {
            countS[s[i] - 'a']++;
            countS[s[i - p.length()] - 'a']--;
            if (equal(countP, countP + 26, countS)) {
                result.push_back(i - p.length() + 1);
            }
        }
        return result;
    }
};
