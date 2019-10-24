// 5 - Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

// Time: O(N^2), Space: O(1)

class Solution {
public:
    int getPalindromeLength(const string& s, int L, int R) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        
        return R - L - 1;
    }
    
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        int longestPalindromeLength = 1;
        int longestPalindromeStart = 0;
        
        for (int i = 0; i < s.size() - 1; i++) {
            int currentBestLength = max(getPalindromeLength(s, i, i), getPalindromeLength(s, i, i + 1));
            
            if (currentBestLength > longestPalindromeLength) {
                longestPalindromeLength = currentBestLength;
                longestPalindromeStart = i - (currentBestLength - 1) / 2;
            }
        }
        
        return s.substr(longestPalindromeStart, longestPalindromeLength);
    }
};