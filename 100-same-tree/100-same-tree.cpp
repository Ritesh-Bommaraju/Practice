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
    void helper(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> p2;
        if(p == NULL && q == NULL){
            return true;
        }
        else if(p == NULL || q == NULL){
            return false;
        }
        helper(p, p1);
        helper(q, p2);
        if(p1 == p2){
            return true;
        }
        return false;
    }
};