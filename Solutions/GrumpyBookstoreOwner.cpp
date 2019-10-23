// 1052 - Grumpy Bookstore Owner
// https://leetcode.com/problems/grumpy-bookstore-owner/

// We will track two main fields:
// (1) The amount of people satisfied on non-grumpy days.
// (2) The amount of satisfied if this is one of the 'X' days to be non-grumpy.
//
// We must track field (2) within a window of size 'X'.
// This is done for each index 'i' greater than or equal to 'X' by:
// - Tracking the customer as if the bookstore owner has been non-grumpy today.
// - Removing any customers that would be satisfied at 'i' - 'X'.
//
// If 'X' = 3, 'i' = 6, the owner is always grumpy, and the customers are [1 0 1 2 1 1 7 5]:
// - We would add 7 and remove 1 to field (2).
// - [1 0 1 2 1 1 7 5]
//          ^     ^ 
// - For the problem, we would look at [1 0 1], [0 1 2], [1 2 1], [2 1 1], [1 1 7], and [1 7 5].
// - We would choose the best "Sliding Window", which is [1 7 5] = 13 total satisfied customers.
// - Note that if the owner is not grumpy for some i, it would essentially be 0 at i for the window.

class Solution {
    const int IS_NOT_GRUMPY = 0;
    const int IS_GRUMPY = 1;
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int normallySatisfiedCustomers = 0;
        int calmedOwnerCustomers = 0;
        int maxCalmedOwnerCustomers = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == IS_NOT_GRUMPY)
                normallySatisfiedCustomers += customers[i];
            else
                calmedOwnerCustomers += customers[i];
            
            // For our "Sliding Window" on when to make the owner not grumpy for 'X' days:
            // - If we added "i - X" before, remove it to keep our window length at 'X'.
            if (i >= X && grumpy[i - X] == IS_GRUMPY)
                calmedOwnerCustomers -= customers[i - X];
            
            // Track the best "Sliding Window" to have the owner not grumpy for 'X' days.
            if (calmedOwnerCustomers > maxCalmedOwnerCustomers)
                maxCalmedOwnerCustomers = calmedOwnerCustomers;
        }

        return normallySatisfiedCustomers + maxCalmedOwnerCustomers;
    }
};