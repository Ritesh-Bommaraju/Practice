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
    int deepestLeavesSum(TreeNode* root) {
        int curr_level_sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            curr_level_sum = 0;
            int n = q.size();
            while(n--){
                TreeNode* top = q.front();
                q.pop();
                curr_level_sum += (top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }   
            }
        }
        return curr_level_sum;
    }
};