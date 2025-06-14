class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(const string& start, const string& end, unordered_set<string>& visited) {
        if (!graph.count(start) || !graph.count(end)) return -1.0;
        if (start == end) return 1.0;

        visited.insert(start);
        for (auto& [neighbor, weight] : graph[start]) {
            if (visited.count(neighbor)) continue;
            double res = dfs(neighbor, end, visited);
            if (res != -1.0) return res * weight;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
     
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            graph[u].emplace_back(v, val);
            graph[v].emplace_back(u, 1.0 / val);
        }

        vector<double> results;
        for (auto& q : queries) {
            unordered_set<string> visited;
            results.push_back(dfs(q[0], q[1], visited));
        }
        return results;
    }
};
