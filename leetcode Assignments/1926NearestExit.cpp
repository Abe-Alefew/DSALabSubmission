class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();

        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0], entrance[1]}, 0}); 
        maze[entrance[0]][entrance[1]] = '+';
        while(!q.empty()){
            auto [pos, steps] = q.front(); q.pop();
            int row = pos.first;
            int cols = pos.second;
            vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(auto& [dr,dc]: dir){
                int i = row + dr;
                int j = cols + dc;
                if(i >= 0 && j >= 0 && i < r && j < c && maze[i][j] == '.'){
                    if(i == 0 || j == 0 || i == r-1 || j == c -1){
                        return steps + 1;
                    }
                    q.push({{i,j},steps+1});
                    maze[i][j] = '+';
                }
            }
        }
        return -1;
    }
};