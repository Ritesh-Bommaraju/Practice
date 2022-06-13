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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
            return NULL;
        }
        if (root1 == NULL){
            return root2;
        }
        if (root2 == NULL){
            return root1;
        }
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root1, root2});
        while(!q.empty()){
            auto temp = q.front(); 
            q.pop();
            temp.first->val += temp.second->val;
            if(temp.first->left && temp.second->left){
                q.push({temp.first->left,temp.second->left});
            }
            else if (temp.second->left){
                temp.first->left = temp.second->left;
            }
            if(temp.first->right && temp.second->right){
                q.push({temp.first->right, temp.second->right});
            }
            else if (temp.second->right){
                temp.first->right=temp.second->right; 
            }
        }
        return root1;
    }
};