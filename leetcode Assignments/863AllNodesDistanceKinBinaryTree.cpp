/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        unordered_map<TreeNode*,vector<TreeNode*>> p_map;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(node->left){
                p_map[node].push_back(node->left);
                p_map[node->left].push_back(node);

                q.push(node->left);
            }
            if(node->right){
                p_map[node].push_back(node->right);
                p_map[node->right].push_back(node);

                q.push(node->right);
            }

        }
        vector<int> out;
        set<TreeNode*> vis;
        vis.insert(target);

        queue<pair<TreeNode*,int>> q1;
        q1.push({target,0});

        while(!q1.empty()){
            auto [node,dis] = q1.front();
            q1.pop();
            if(dis == k) out.push_back(node->val);
            else{
                for(auto& edge:p_map[node]){
                    if(vis.find(edge) == vis.end()){
                        vis.insert(edge);
                        q1.push({edge,dis+ 1});
                    }
                }
            }
        }
        return out;
    }
};