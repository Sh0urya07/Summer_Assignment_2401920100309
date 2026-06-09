class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        int count1[26] = {0};
        int count2[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        if (equal(count1, count1 + 26, count2)) {
            return true;
        }
        for (int i = s1.length(); i < s2.length(); i++) {
            count2[s2[i] - 'a']++;
            count2[s2[i - s1.length()] - 'a']--;
            if (equal(count1, count1 + 26, count2)) {
                return true;
            }
        }
        return false;
    }
};
