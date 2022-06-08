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
    void helper(TreeNode* root, vector<int>&nodes){
        if(root == NULL){
            return;
        }
        helper(root->left, nodes);
        nodes.push_back(root->val);
        helper(root->right, nodes);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nodes;
        helper(root, nodes);
        int min_diff = INT_MAX;
        for(int i = 0; i < nodes.size() - 1; i++){
            min_diff = min(min_diff, nodes[i+1]-nodes[i]);
        }
        return min_diff;
    }
};