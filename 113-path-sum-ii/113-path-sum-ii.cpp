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
    vector<vector<int>> ans;
    void helper(TreeNode* root, vector<int> path, int curr){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == curr){
                path.push_back(root->val);
                ans.push_back(path);
                return;
            }
        }
        path.push_back(root->val);
        helper(root->left, path, curr - root->val);
        helper(root->right, path, curr - root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(root == NULL){
            return ans;
        }
        vector<int> path;
        helper(root, path, target);
        return ans;
    }
};