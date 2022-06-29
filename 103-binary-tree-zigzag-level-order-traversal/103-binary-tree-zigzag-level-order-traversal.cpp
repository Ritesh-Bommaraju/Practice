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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool zig = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> path(size);
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                int index = (zig) ? i : size - i - 1;
                
                path[index] = curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            //after this level
            zig = !zig;
            ans.push_back(path);
        }
        return ans;
    }
};