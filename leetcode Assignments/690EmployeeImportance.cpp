/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int imp = 0;
        unordered_map<int, Employee*> empMap;
        for(auto&  em: employees){
            empMap[em->id] = em;
        }
        queue<Employee*> q;
        q.push(empMap[id]);
        while(q.size() > 0){
            Employee* e = q.front();
            q.pop();
            imp += e -> importance;
            for(int subID: e->subordinates){
                q.push(empMap[subID]);
            }
        }
        return imp;
    }
};