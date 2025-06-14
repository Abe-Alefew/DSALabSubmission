class Solution {
public:
    set<int> vis;
    int province = 0;
    
    void dfs(int i,vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vis.insert(i);
        for(int j = 0; j < n; j++ ){
            if(isConnected[i][j] && vis.find(j) == vis.end()) dfs(j,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 0; i< n; i++){
            if(vis.find(i) == vis.end()){
                province++;
                dfs(i, isConnected);
            }
        } 
        return province;
    }
};