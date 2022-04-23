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
    vector<TreeNode*> v;
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        // if (!root) return tail;
        // TreeNode* res = increasingBST(root->left, root);
        // root->left = NULL;
        // root->right = increasingBST(root->right, tail);
        // return res;
        inorder(root);
        for(int i = 0; i < v.size() - 1; i++){
            v[i]->right = v[i+1];
            v[i]->left = NULL;
        }
        v[v.size() - 1]->right = NULL;
        v[v.size() - 1]->left = NULL;
        return v[0];
        
    }
    void inorder(TreeNode* node){
        if(node == NULL){
            return;
        }
        inorder(node->left);
        v.push_back(node);
        inorder(node->right);
    }
};