// 1 - Two Sum
// https://leetcode.com/problems/two-sum/submissions/

// Track the "complement" along with an index, which is used for the solution.
// - Ultimately, we want to find nums[A] + nums[B] = target.
// - So, for each nums[i], we should store { target - nums[i]: i }.
// - If it already exists, then we know to return the index stored and the current index.
//
// Given [2, 11, 7, 15], target = 9:
// - i = 0 with complement mapping {}
// --- nums[i] = 2
// --- nums[i] does not exist in the mapping, so we track that we saw it using the complement.
// --- complement = target - nums[i] = 9 - 2 = 7
//
// - i = 1 with complement mapping { 7:0 }
// --- nums[i] = 11
// --- nums[i] does not exist in the mapping, so we track that we saw it using the complement.
// --- complement = target - nums[i] = 9 - 11 = -2
//
// - i = 2 with complement mapping { 7:0, -2:1 }
// --- nums[i] = 7
// --- nums[i] does exist! Let's return whatever index is mapped and the current index.
// --- Return [0, 2].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            if (complements.find(nums[i]) == complements.end())
                complements[target - nums[i]] = i;
            else {
                result.push_back(complements[nums[i]]);
                result.push_back(i);
                break;
            }
        }
        
        return result;
    }
};