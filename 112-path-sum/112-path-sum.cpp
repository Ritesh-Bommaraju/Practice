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
    bool hasPathSum(TreeNode* root, int target) {
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == target){
                return true;
            }
            return false;
        }
        return hasPathSum(root->left, target - root->val) || hasPathSum(root->right, target - root->val);
    }
};