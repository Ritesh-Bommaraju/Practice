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
    void ls2(TreeNode* root, vector<int> &v){
        if(!root->left && !root->right){
            v.push_back(root->val);
        }
        if(root->right)
        ls2(root->right, v);
        if(root->left)
        ls2(root->left, v);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        ls2(root1, v1);
        ls2(root2, v2);
        
        if(v1==v2){
            return true;
        }
        return false;
    }
};