class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        
        vector<vector<int>> output(r, vector<int>(c, -1));
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;

        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    vis.insert({i, j});
                    output[i][j] = 0;
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [cur_r, cur_c] = q.front();
            q.pop();
            int height = output[cur_r][cur_c];

            for (auto& [dr, dc] : dirs) {
                int new_r = cur_r + dr;
                int new_c = cur_c + dc;

                if (new_r < 0 || new_c < 0 || new_r >= r || new_c >= c || vis.count({new_r, new_c}))
                    continue;

                q.push({new_r, new_c});
                vis.insert({new_r, new_c});
                output[new_r][new_c] = height + 1;
            }
        }

        return output;
    }
};
