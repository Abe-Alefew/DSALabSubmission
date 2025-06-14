class Solution {
public:
    vector<vector<int>> grid;
    unordered_map<int, vector<pair<int,int>>> dir;

    bool connect(int x1, int y1, int x2, int y2) {
        int street1 = grid[x1][y1];
        int street2 = grid[x2][y2];

        for (auto& [dx1,dy1] : dir[street1]) {
            if (x1 + dx1 == x2 && y1 + dy1 == y2) {
                for (auto& [dx2,dy2] : dir[street2]) {
                    if (x2 + dx2 == x1 && y2 + dy2 == y1)
                        return true;
                }
            }
        }
        return false;
    }


    bool hasValidPath(vector<vector<int>>& grid) {
        this->grid = grid;
        int m = grid.size();
        int n = grid[0].size();

        dir = {
            {1, {{0, -1}, {0, 1}}},
            {2, {{-1, 0}, {1, 0}}},
            {3, {{0, -1}, {1, 0}}},
            {4, {{0, 1}, {1, 0}}},
            {5, {{-1, 0}, {0, -1}}},
            {6, {{-1, 0}, {0, 1}}}
        };

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        seen[0][0] = true;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == m - 1 && y == n - 1) return true;

            for (auto& [dx,dy] : dir[grid[x][y]]) {
                int n_x = x + dx;
                int n_y = y + dy;
                if (n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && !seen[n_x][n_y]) {
                    if (connect(x, y, n_x, n_y) == true) {
                        seen[n_x][n_y] = true;
                        q.push({n_x, n_y});
                    }
                }
            }
        }

        return false;
    }
};
