class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,1},{1,-1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];

        int m = board.size();
        int n = board[0].size();

        if(board[r][c] == 'M' || board[r][c] == 'X'){
            board[r][c] = 'X';
            return board;
        }

        int count = 0;
        for(auto& [dr,dc]:dir){
            int n_r = r + dr;
            int n_c = c + dc;

            if(n_r >= 0 && n_r < m && n_c >= 0 && n_c < n && board[n_r][n_c] == 'M') count++;
        }
        if(count > 0){
            board[r][c] = '0' + count;
            return board;
        }

        board[r][c] = 'B';
         for(auto& [dr,dc]:dir){
            int n_r = r + dr;
            int n_c = c + dc;

            if(n_r >= 0 && n_r < m && n_c >= 0 && n_c < n && board[n_r][n_c] == 'E') {
                vector<int> n_click = {n_r,n_c};
                updateBoard(board,n_click);
            }
        }
        return board;
    }
};