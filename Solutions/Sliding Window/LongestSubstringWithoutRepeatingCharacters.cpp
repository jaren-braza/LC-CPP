// 3 - Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// We will maintain window [L, R] of unique characters.
// 
// How do we make sure the characters in the range [L, R] are unique?
// - We will have a map on where a character was last seen.
// - We will grow one character at a time to the right.
// - If that character is already seen, we may have to adjust the left.
// 
// Whenever a character we have seen appears on the right end of our window:
// - Remove it if it is within the window by moving L just past where it was last seen.
// - Example:
// --- For [a b c w d e f w g], we must move L past when we last saw 'w'.
//              L         R
//
// --- So, [a b c w d e f w g] would be the result.
//                  L     R
//
// --- If L was already past the first 'w', then we would not have to adjust L.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int longest = 0;
        int L = 0;

        for (int R = 0; R < s.size(); R++) {
            char charToAddToWindow = s[R];

            // If this is a character we have already seen and it is inside the window
            // - Set our left-end to be just past where it was last seen
            if (lastSeen.find(charToAddToWindow) != lastSeen.end())
                if (L <= lastSeen[charToAddToWindow])
                    L = lastSeen[charToAddToWindow] + 1;

            lastSeen[charToAddToWindow] = R;

            if (R - L + 1 > longest)
                longest = R - L + 1;
        }

        return longest;
    }
};