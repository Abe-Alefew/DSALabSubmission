class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<pair<int,int>> dir = {{0,1}, {0,-1},{1,0},{-1,0}};

        queue<pair<int,int>> q;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if (mat[i][j] == 0) q.push({i,j});
                else{
                   mat[i][j] = INT_MAX; 
                }
            }
        }

        while(!q.empty()){
            auto [cur_r,cur_c] = q.front();
            q.pop();



            for(auto& [dr,dc]: dir){
                int n_r = cur_r + dr;
                int n_c = cur_c + dc;

                if(n_r >= 0 && n_r < r && n_c >=0 && n_c < c && mat[n_r][n_c] > mat[cur_r][cur_c] + 1){
                    mat[n_r][n_c] = mat[cur_r][cur_c] + 1;
                    q.push({n_r,n_c});
            }
        }

        


        }
        return mat;
    }
};