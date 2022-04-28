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
    int long long sum = 0;
    int long long maxprod = 0;
    void totalsum(TreeNode* root){
        if(root == NULL){
            return;
        }
        totalsum(root->left);
        totalsum(root->right);
        sum += root->val;
    }
    
    int maxProduct(TreeNode* root) {
        totalsum(root);
        calmaxprod(root);
        return (int)(maxprod % (int)(1e9 + 7));
        
        
    }
    int calmaxprod(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int left = calmaxprod(node->left);
        int right = calmaxprod(node->right);
        int currsum = left + right + node->val;
        maxprod = max(maxprod, (sum - currsum)*currsum);
        return currsum;
    }
};