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
    unordered_map<int,int> mp;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int &preorder_index) {
        if(left > right){
            return NULL;
        }
        int curr = mp[preorder[preorder_index]];
        TreeNode *root = new TreeNode(preorder[preorder_index]);
        preorder_index ++;
        root->left = helper(preorder, inorder, left, curr-1, preorder_index);
        root->right = helper(preorder, inorder, curr+1, right, preorder_index);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }
        int preorder_index = 0;
        return helper(preorder, inorder, 0, n-1, preorder_index);
    }
};