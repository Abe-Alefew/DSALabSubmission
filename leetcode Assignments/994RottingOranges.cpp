class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int time = 0;
        int fresh = 0;
        queue<pair<int, int>> q;

        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [cur_r, cur_c] = q.front();
                q.pop();

                for (auto& [dr, dc] : dir) {
                    int n_r = cur_r + dr;
                    int n_c = cur_c + dc;

                    if (n_r >= 0 && n_r < r && n_c >= 0 && n_c < c && grid[n_r][n_c] == 1) {
                        grid[n_r][n_c] = 2;
                        q.push({n_r, n_c});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
