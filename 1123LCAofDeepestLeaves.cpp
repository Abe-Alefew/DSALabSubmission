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
    TreeNode* cand = nullptr;
    int maxD = -1;
    int dfs(TreeNode* root, int depth){
        if(!root) return -1;
        if(!root->left && !root->right){
            if(depth > maxD){
                cand = root;
                maxD = depth;
            }
            return depth;
        }
        int l_dep = dfs(root->left, depth +1);
        int r_dep = dfs(root->right, depth +1);

        if(l_dep == r_dep && l_dep == maxD){
            cand = root;
        }
        return max(l_dep,r_dep);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;

        dfs(root, 0);
        return cand;
    }
};