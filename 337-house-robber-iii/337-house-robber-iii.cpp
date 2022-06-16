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
    unordered_map<TreeNode*, int> mp;
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        if(mp.find(root) != mp.end()){
            return mp[root];
        }
        
        // including the curr root;
        
        int including = root->val;
        
        if(root->left != NULL){
            including += helper(root->left->left) + helper(root->left->right);
        }
        if(root->right != NULL){
            including += helper(root->right->left) + helper(root->right->right);
        }
        
        // excluding the curr root
        
        int excluding = helper(root->left) + helper(root->right);
        int ans = mp[root] = max(including, excluding);
        return ans;
    }
    int rob(TreeNode* root) {
        return helper(root);
    }
};
