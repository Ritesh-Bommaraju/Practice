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
    void helper(TreeNode* root, int &count, int max_so_far){
        if(root == NULL){
            return;
        }
        if(root->val >= max_so_far){
            count++;
            max_so_far = root->val;
        }
        helper(root->left, count, max_so_far);
        helper(root->right, count, max_so_far);
        
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        if(root == NULL){
            return count;
        }
        helper(root, count, root->val);
        return count;
    }
};