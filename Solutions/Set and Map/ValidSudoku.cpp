// 36 - Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

// We will check that each aspect of a Sudoku board is valid.
// 
// Search each aspect, keeping track of unique characters with a set.
// - Search each row, which is straightforward.
// - Search each column, which is straightforward.
// - Search each sub-box, which needs a little bit more attention.
// --- Start at the top-left corner.
// --- Explore the 3x3 sub-box.
//
// Complexity
// - Let N be the length of the board.
//
// - We do three full sweeps of the board.
// --- Checking each row.
// --- Checking each column.
// --- Checking each sub-box.
// - Thus, time complexity is O(N * N), bounded by the area of the board.
// 
// - We keep track of unique characters by using a set.
// --- At worst, we will have to store all characters in a row, column, or sub-box.
// - Thus, space complexity is O(N).

class Solution {
    const int SUB_BOX_SIZE = 3;
    const int BOARD_SIZE = 9;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check that each row is valid
        for (int row = 0; row < BOARD_SIZE; row++) {
            set<char> seen;
            
            for (int col = 0; col < BOARD_SIZE; col++) {
                char cellValue = board[row][col];
                
                if (seen.find(cellValue) != seen.end())
                    return false;
                
                if (cellValue != '.')
                    seen.insert(cellValue);
            }
        }
        
        // Check that each column is valid
        for (int col = 0; col < BOARD_SIZE; col++) {
            set<char> seen;
            
            for (int row = 0; row < BOARD_SIZE; row++) {
                char cellValue = board[row][col];
                
                if (seen.find(cellValue) != seen.end())
                    return false;
                
                if (cellValue != '.')
                    seen.insert(cellValue);
            }
        }
        
        // Check that each sub-box is valid
        for (int boxRowStart = 0; boxRowStart < BOARD_SIZE; boxRowStart += SUB_BOX_SIZE) {
            for (int boxColStart = 0; boxColStart < BOARD_SIZE; boxColStart += SUB_BOX_SIZE) {
                set<char> seen;
                
                for (int row = boxRowStart; row < boxRowStart + SUB_BOX_SIZE; row++) {
                    for (int col = boxColStart; col < boxColStart + SUB_BOX_SIZE; col++) {
                        char cellValue = board[row + dr[i]][col + dc[i]];
                        
                        if (seen.find(cellValue) != seen.end())
                            return false;
                        
                        if (cellValue != '.')
                            seen.insert(cellValue);
                    }
                }
            }
        }
        
        return true;
    }
};