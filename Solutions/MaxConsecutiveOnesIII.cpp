// 1004 - Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/

// We will maintain window [L, R] of the largest window satisfying:
// - There were at most K zeroes when the window grew to this size.
//
// We will only "grow" if there is at most K zeroes.
// - If there is more than K zeroes, the entire window is shifted instead. 

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int numberOfZeroes = 0;
        int longest = 0;
        int L = 0;
        
        for (int R = 0; R < A.size(); R++) {
            if (A[R] == 0)
                numberOfZeroes++;
            
            // If the window is invalid, shift the window instead of growing it
            if (numberOfZeroes > K) {
                if (A[L] == 0)
                    numberOfZeroes--;
                
                L++;
            }
            
            if (R - L + 1 > longest)
                longest = R - L + 1;
        }
        
        return longest;
    }
};