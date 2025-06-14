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
    int subTreeSum(TreeNode* root, int parentVal, int grandParentVal){
        int sum = 0;
        if(!root) return 0;
        if(grandParentVal % 2 == 0 && grandParentVal != -1) sum += root->val;
        if(!root->right && root->left) return sum + subTreeSum(root->left,root->val, parentVal);
        if(!root->left && root->right) return sum + subTreeSum(root->right,root->val, parentVal);
        else{
            return sum+ subTreeSum(root->left,root->val, parentVal) + subTreeSum(root->right,root->val,parentVal);
        }
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        return subTreeSum(root,-1,-1);
    }
};