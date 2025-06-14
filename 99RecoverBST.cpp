/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> temp;

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        temp.push_back(root);
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        vector<int> srted;
        for(auto& n:temp){
            srted.push_back(n->val);
        }
        sort(srted.begin(),srted.end());
        for(int i = 0; i <srted.size(); i++){
            temp[i]->val = srted[i];
        }
    }
};