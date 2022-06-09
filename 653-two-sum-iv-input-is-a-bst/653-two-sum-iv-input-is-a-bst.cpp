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
    vector<int> nodes;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int target) {
        inorder(root);
        int s = 0;
        int e = nodes.size() - 1;
        while(s < e){
            if(nodes[s] + nodes[e] == target){
                return true;
            }
            else if(nodes[s] + nodes[e] > target){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
        
    }
};