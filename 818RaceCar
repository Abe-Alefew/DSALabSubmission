class Solution {
public:
    int racecar(int target) {
        queue<pair<int, pair<int, int>>> q; 
        set<pair<int, int>> vis;            

        q.push({0, {0, 1}}); 

        while (!q.empty()) {
            auto [m, ps] = q.front();
            q.pop();
            int p = ps.first;
            int s = ps.second;

            if (p == target) return m;

            if (vis.count({p, s})) continue;
            vis.insert({p, s});

            
            q.push({m + 1, {p + s, s * 2}});

            
            if ((s > 0 && p + s > target) || (s < 0 && p + s < target)) {
                q.push({m + 1, {p, s > 0 ? -1 : 1}});
            }
        }

        return -1; 
    }
};
