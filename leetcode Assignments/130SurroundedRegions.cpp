class Solution {
public:
    void capture(int r, int c, vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') return;

        board[r][c] = '#'; // temporary marking
        capture(r + 1, c, board);
        capture(r - 1, c, board);
        capture(r, c + 1, board);
        capture(r, c - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int r = board.size();
        int c = board[0].size();

        // Capturing the unsurroundred  regions
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') capture(i, 0, board);
            if (board[i][c - 1] == 'O') capture(i, c - 1, board);
        }
        // Capturing the surrounded regions
        for (int j = 0; j < c; j++) {
            if (board[0][j] == 'O') capture(0, j, board);
            if (board[r - 1][j] == 'O') capture(r - 1, j, board);
        }

        // Uncapturing unsurrounded regions
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
