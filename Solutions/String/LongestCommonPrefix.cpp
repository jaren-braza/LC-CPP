// 14 - Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

// Using the first string as reference:
// - Build up the common prefix.
// - Stop if our prefix grows larger than any string or does not exist for any string.
//
// If 'N' is the number of strings we have, and 'P' is the length of the longest prefix, then:
// Time: O(NP), Space: O(1)
//
// For Time, this is the best we can do because:
// - We have to look at every string up to the length of the smallest string

class Solution {
public:
    bool havePrefix(vector<string>& strs, char prefixCharIndex) {
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].size() <= prefixCharIndex)
                return false;
            
            if (strs[0][prefixCharIndex] != strs[i][prefixCharIndex])
                return false;
        }
        
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        int endingIndexOfPrefix = 0;
        
        for (int i = 0; i < strs[0].size(); i++) {
            if (!havePrefix(strs, i))
                break;
            
            endingIndexOfPrefix++;
        }
        
        return strs[0].substr(0, endingIndexOfPrefix);
    }
};