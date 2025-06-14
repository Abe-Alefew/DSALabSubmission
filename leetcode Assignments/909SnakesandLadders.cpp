class Solution {
public:
    int n;

    pair<int, int> intToPos(int s) {
        int r = (s - 1) / n;
        int c = (s - 1) % n;
        if (r % 2 != 0) c = n - 1 - c; // reverse column on odd rows
        return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        reverse(board.begin(), board.end()); // flip the board vertically

        queue<pair<int, int>> q;
        q.push({1, 0}); // {square, moves}
        set<int> vis;
        vis.insert(1);

        while (!q.empty()) {
            auto [s, m] = q.front();
            q.pop();

            for (int i = 1; i <= 6; ++i) {
                int nextS = s + i;
                if (nextS > n * n) continue;

                auto [r, c] = intToPos(nextS);
                if (board[r][c] != -1) {
                    nextS = board[r][c];
                }

                if (nextS == n * n) return m + 1;

                if (vis.find(nextS) == vis.end()) {
                    vis.insert(nextS);
                    q.push({nextS, m + 1});
                }
            }
        }

        return -1;
    }
};
