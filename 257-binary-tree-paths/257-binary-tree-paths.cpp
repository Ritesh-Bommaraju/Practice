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
    vector<string> ans;
    void helper(TreeNode* root, string s){
        if(root == NULL){
            return;
        }
        if(s.size() == 0){
            s += to_string(root->val);
        }
        else{
            s += ("->"+to_string(root->val));
        }
        if(root->left || root->right){
            helper(root->left, s);
            helper(root->right, s);
        }
        else{
            ans.push_back(s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root != NULL){
            helper(root, "");
        }
        return ans;
        
    }
};