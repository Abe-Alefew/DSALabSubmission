class Solution {
public:
    vector<bool> vis;
    void dfs(vector<vector<int>>& rooms, int ind){
        for(int i = 0; i < rooms[ind].size(); ++i){
            int nxt = rooms[ind][i];
            if(!vis[nxt]) {
                vis[nxt] = true;
                dfs(rooms, nxt);}
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(), false);
        vis[0] = true;
        dfs(rooms,0);
        for(bool b : vis) if(!b) return false;
        return true;

    }
};