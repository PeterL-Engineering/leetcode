class Solution {
public:
    bool dfs(vector<vector<char>>& board, int boardSize, int boardColSize, int i, int j, string word, int k) {

        // Whole word matched
        if (word[k] == '\0') return true;

        // Out of bounds or cell doesn't match (also catches '#' visited cells)
        if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize) return false;
        if (board[i][j] != word[k]) return false;

        char c = board[i][j];    // save original letter
        board[i][j] = '#';      // mark as visited

        bool found = dfs(board, boardSize, boardColSize, i - 1, j, word, k + 1) ||
                     dfs(board, boardSize, boardColSize, i + 1, j, word, k + 1) ||
                     dfs(board, boardSize, boardColSize, i, j - 1, word, k + 1) ||
                     dfs(board, boardSize, boardColSize, i, j + 1, word, k + 1);

        board[i][j] = c;        // backtrack: restore the letter
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int boardSize = board.size();
        int boardColSize = board[0].size();

        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardColSize; j++) {
                if (dfs(board, boardSize, boardColSize, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
        
    }
};