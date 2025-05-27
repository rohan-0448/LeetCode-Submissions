class Solution {
public:
    bool valid(int row, int col, vector<vector<string>> board) {
        int n = board.size();
        // check row 
        for(int i=0; i<n; i++) { 
            if(i != row) {
                if(board[i][col] == "Q") {
                    return false;
                }
            }
        }
        // check col
        for(int j=0; j<n; j++) {
            if(j != col) {
                if(board[row][j] == "Q") {
                    return false;
                }
            }
        }

        // digonal check
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == "Q") {
                return false;
            }
        }

        for(int i = row+1, j = col+1; i < n && j < n; i++ , j++) {
            if(board[i][j] == "Q") {
                return false;
            }
        }

        // Check upper-right diagonal (↗)
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == "Q") {
                return false;
            }
        }

        for(int i = row+1, j = col-1; i < n && j >= 0; i++, j--) {
            if(board[i][j] == "Q") {
                return false;
            }
        }
        // // check diagonal - 1
        // int mn = min(row, col), mx = max(row, col);
        // int nrow = row - mn;
        // int ncol = col - mn;
        // for(int i=0; i<(n-mx); i++) {
        //     if(nrow + i != row && ncol + i != col) {
        //         if(board[nrow][ncol] == "Q") {
        //             return false;
        //         }
        //     }
        // }
        // // check diagonal - 2
        // for(auto &i: board) reverse(i.begin(), i.end());
        // col = n-col-1;

        // mn = min(row, col), mx = max(row, col);
        // nrow = row - mn;
        // ncol = col - mn;
        // for(int i=0; i<(n-mx); i++) {
        //     if(nrow + i != row && ncol + i != col) {
        //         if(board[nrow][ncol] == "Q") {
        //             return false;
        //         }
        //     }
        // }
        return true;
    }

    void recursive(int n, int row, int queens, vector<vector<string>>& board, vector<vector<string>>& ans) {
        if(queens != row) return;
        if(row == n) {
            vector<string> fin;
            for(auto it: board) {
                string s = "";
                for(auto i: it) {
                    s += i;
                }
                fin.push_back(s);
            }
            ans.push_back(fin);
            return;
        }

        for(int col=0; col<n; col++) {
            if(valid(row, col, board)) {
                board[row][col] = "Q";
                recursive(n, row+1, queens+1, board, ans);
                board[row][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<string>> board(n, vector<string> (n, "."));
        recursive(n, 0, 0, board, ans);
        
        return ans;
    }
};