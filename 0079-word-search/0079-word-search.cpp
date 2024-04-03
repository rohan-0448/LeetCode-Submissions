class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool check(vector<vector<int>> &visited, int rows, int cols, vector<vector<char>> &board, string word, int x, int y, string curr_word){
//         if(curr_word == word) return true;
        
//         if(x == rows || y == cols || x == -1 || y == -1 || visited[x][y] == 1) return false;
//         // if() return false;
//         // if() return false;
//         // if(x == rows-1 && y == cols-1) return (board[x][y] == word[index]); 
//         // else if(x == rows-1 && y != cols-1) return check(rows, cols, board, word, x, y+1, index+1);
//         // else if(x != rows-1 && y == cols-1) return check(rows, cols, board, word, x+1, y, index+1);
//         visited[x][y] = 1;
//         return check(visited, rows, cols, board, word, x, y+1, curr_word+board[x][y]) || check(visited, rows, cols, board, word, x+1, y, curr_word+board[x][y]) || check(visited, rows, cols, board, word, x, y-1, curr_word+board[x][y]) || check(visited, rows, cols, board, word, x-1, y, curr_word+board[x][y]);
//     }
    
//     bool exist(vector<vector<char>>& board, string word) {
//         int row = board.size(), col = board[0].size();
//         vector<vector<int>> visited(row, vector<int> (col, 0));
//         for(int i=0; i<row; i++){
//             for(int j=0; j<col; j++){
//                 if(board[i][j] == word[0]) if(check(visited, row, col, board, word, i, j, "")) return true;
//             }
//         }
//         return false;
//     }
// };