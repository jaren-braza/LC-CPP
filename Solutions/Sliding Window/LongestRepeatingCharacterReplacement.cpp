// 424 - Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/

// We will maintain window [L, R] satisfying:
// - Its length is bounded by the number of allowed replacements and the largest character count

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> charCount;
        int L = 0;
        int maxCount = 0;
        
        for (int R = 0; R < s.size(); R++) {
            charCount[s[R]]++;
            
            if (charCount[s[R]] > maxCount)
                maxCount = charCount[s[R]];
            
            while (R - L + 1 > k + maxCount) {
                charCount[s[L]]--;
                L++;
            }
        }
        
        return s.size() - L;
    }
};