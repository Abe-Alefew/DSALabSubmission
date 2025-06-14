class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //edge cases
        int n = routes.size();
        if(source == target) return 0;
        unordered_map<int, vector<int>> stopR;
        unordered_set<int> visS;
        vector<int> visR(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            for(int stop :routes[i]){
                stopR[stop].push_back(i);
            }
        }
        q.push(source);
        visS.insert(source);
        int buses = 0;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                int stop = q.front();
                q.pop();
            if(stop == target) return buses;
            for(int route: stopR[stop]){
                if(visR[route] != 0) continue;
                visR[route] = 1;
                for(int nextS: routes[route]){
                    if(visS.count(nextS) == 0){
                        visS.insert(nextS);
                        q.push(nextS);
                    }
                }
            }
            }
            buses++;
        }
        return -1;

    }
};