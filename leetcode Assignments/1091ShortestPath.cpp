class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0][0] != 0 || grid.back().back() != 0)
            return -1;
        
        int s = grid.size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        
        q.push({0, 0});
        grid[0][0] = 1; // start with length 1

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int leng = grid[r][c];

            if (r == s - 1 && c == s - 1)
                return leng;

            for (auto& [dr, dc] : dir) {
                int n_r = r + dr;
                int n_c = c + dc;

                if (n_r >= 0 && n_r < s && n_c >= 0 && n_c < s && grid[n_r][n_c] == 0) {
                    grid[n_r][n_c] = leng + 1;
                    q.push({n_r, n_c});
                }
            }
        }

        return -1;
    }
};
