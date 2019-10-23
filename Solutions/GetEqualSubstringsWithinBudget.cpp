// 1208 - Get Equal Substrings Within Budget
// https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int L = 0;
        
        for (int R = 0; R < s.size(); R++) {
            maxCost -= abs(s[R] - t[R]);
            
            if (maxCost < 0) {
                maxCost += abs(s[L] - t[L]);
                L++;
            }
        }
        
        return s.size() - L;
    }
};