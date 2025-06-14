class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) q.push({i, j});
            }
        }

        
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int output = -1;

        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            output = grid[r][c];

            for (auto& [dr, dc] : dir) {
                int n_r = r + dr;
                int n_c = c + dc;

                if (n_r >= 0 && n_r < n && n_c >= 0 && n_c < n && grid[n_r][n_c] == 0) {
                    q.push({n_r, n_c});
                    grid[n_r][n_c] = grid[r][c] + 1; 
                }
            }
        }

       
        return output > 1 ? output - 1 : -1;
    }
};
