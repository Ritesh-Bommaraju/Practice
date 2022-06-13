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
// Self Notes: 
// \U0001f4a1 Mirror property is    left == right and right == left
// \U0001f4a1 pre-order traversal on root->left subtree, (root, left, right)
// \U0001f4a1 modified pre-order traversal on root->right subtree, (root, right, left) 
// \U0001f4a1 compare the node val's if they are the same 
// \U0001f4a1 Do both traversals at the same time
// \U0001f4a1 if left is null or right is null, then both sides must match and return true (base case)
class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            if(left == right){
                return true;
            }
            return false;
        }
        if(left->val != right->val){
            return false;
        }
        bool temp = helper(left->left, right->right) && helper(left->right, right->left);
        return temp;
    }
    bool isSymmetric(TreeNode* root) {
       if(root == NULL){
           return false;
       }
       return helper(root->left, root->right); 
    }
    
};