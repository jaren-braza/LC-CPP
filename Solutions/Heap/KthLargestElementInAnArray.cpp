// 215 - Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// The obvious answer is to sort and pick out the kth element from the end.
// This would be done in O(NlogN) time and O(1) space.
//
// If we are able to track the 'K' largest elements in O(logK) time, it would be better.
// For some container of size 'K', what inserts and deletes elements in O(logK) time? Heaps!
// This would trade a faster time complexity of O(NlogK) for a worse space complexity of O(K).
//
// We will track the current 'K' largest elements.
// - A min-heap is used so that the smallest is kicked out every time a larger number is seen.
//
// In essence:
// - Put in the first 'K' elements into a min-heap.
// - For each of the other elements, if it is larger than the current min from the min-heap:
// --- Kick the min from the min-heap out, and put the new larger number in.
// - At the end, the smallest of the 'K' largest elements will be at the top of the min-heap.
// - In other words, we would have the 'K'th largest element.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < k; i++)
            minHeap.push(nums[i]);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        
        return minHeap.top();
    }
};