class Solution {
public:
    int maxA = 0;
    void dfs(int r, int c, int m, int n, vector<vector<int>>& grid, int& curA){
        if( r < 0 || r >= m || c< 0|| c>=n || grid[r][c] == 0) return ;
        grid[r][c] = 0;
        curA++;
        maxA = max(maxA,curA);

        dfs(r - 1, c, m, n, grid, curA);
        dfs(r + 1, c, m, n, grid, curA);
        dfs(r, c - 1, m, n, grid, curA);
        dfs(r, c + 1, m, n, grid, curA);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r == 0) return 0;
        maxA = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    int curA = 0;
                    dfs(i,j,r,c,grid,curA);
                }
            }
        }
        return maxA;
    }
};