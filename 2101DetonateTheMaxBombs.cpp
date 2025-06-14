class Solution {
public:
    unordered_map<int,vector<int>> graph;
    
    void dfs(int i,unordered_set<int>&  vis){
        vis.insert(i);
        for(int child : graph[i]){
            if(vis.find(child) == vis.end()){
                
                dfs(child,vis);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        graph.clear();//for reusing
        int n = bombs.size();
        for( int i = 0; i < n; i++){
            long long x1 = bombs[i][0];
            long long  y1 = bombs[i][1];
            long long r = bombs[i][2];
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long dx = x1 - x2;
                long long dy = y1 - y2;
                if(dx * dx + dy * dy <= r * r){
                    graph[i].push_back(j);
                }
            }
        }

        int output = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> vis;            
            dfs(i,vis);
            output = max(output,(int)vis.size());
        }
        return output;
    }
};