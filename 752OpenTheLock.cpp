class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis(deadends.begin(), deadends.end());
        if(vis.find("0000") != vis.end()) return -1;

        while(!q.empty()){
            auto [lock, t] = q.front();
            q.pop();

            if (lock == target) return t;
            for(int i = 0; i < 4; ++i){
                for(int change: {-1,1}){
                    int new_Dig = (lock[i] -'0' + change + 10) % 10;
                    string new_lock = lock;
                    new_lock[i] = '0' + new_Dig;

                    if(vis.find(new_lock) == vis.end()){
                        vis.insert(new_lock);
                        q.push({new_lock, t +1});
                    } 

                }
            }
        }
    return -1;
    }
};