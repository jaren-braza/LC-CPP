// 17 - Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// We will keep track of all possible combinations.
// - Start off with no current combinations.
// - For each digit:
// --- Combine the current combinations with each letter mapped from the digit.
//
// If we have "23":
// 1. Current Combinations: { "" }
// --- We want to combine possibilities from '2', the first digit we come across.
// --- Note that '2' maps to { 'a', 'b', 'c' }
// --- "" + 'a' = "a"
// --- "" + 'b' = "b"
// --- "" + 'c' = "c"
// 
// 2. Current Combinations: { "a", "b", "c" }
// --- We want to combine possibilities from '3', the next digit we come across.
// --- Note that '3' maps to { 'd', 'e', 'f' }
// --- "a" + 'd' = "ad"
// --- "a" + 'e' = "ae"
// --- "a" + 'f' = "af"
// --- "b" + 'd' = "bd"
// --- "b" + 'e' = "be"
// --- "b" + 'f' = "bf"
// --- "c" + 'd' = "cd"
// --- "c" + 'e' = "ce"
// --- "c" + 'f' = "cf"
//
// 3. Current Combinations: { "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf" }
// --- We have accounted for all of the digits, so we are done!

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string>();
        
        unordered_map<char, string> digitToLetters = getDigitToLetters();
        vector<string> letterCombinations = {""};
        
        for (char digit : digits) {
            string possibleLetters = digitToLetters[digit];
            vector<string> nextCombinations;
            
            for (string oldCombination : letterCombinations)
                for (char letter : possibleLetters)
                    nextCombinations.push_back(oldCombination + letter);
            
            letterCombinations = nextCombinations;
        }
        
        return letterCombinations;
    }
private:
    unordered_map<char, string> getDigitToLetters() {
        unordered_map<char, string> digitToLetters;
        
        digitToLetters['2'] = "abc";
        digitToLetters['3'] = "def";
        digitToLetters['4'] = "ghi";
        digitToLetters['5'] = "jkl";
        digitToLetters['6'] = "mno";
        digitToLetters['7'] = "pqrs";
        digitToLetters['8'] = "tuv";
        digitToLetters['9'] = "wxyz";
        
        return digitToLetters;
    }
};