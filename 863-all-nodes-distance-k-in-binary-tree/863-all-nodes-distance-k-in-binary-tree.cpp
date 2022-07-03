/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> graph[500];
    void makeadjlist(TreeNode* root){
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            makeadjlist(root->left);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            makeadjlist(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0){
            return {target->val};
        }
        queue<int> q;
        q.push(target->val);
        makeadjlist(root);
        int curr_dist = 0;
        vector<bool> vis(500,0);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();
                vis[curr] = 1;
                for(int neigbhour : graph[curr]){
                    if(!vis[neigbhour]){
                        q.push(neigbhour);
                    }
                }
            }
            curr_dist++;
            if(curr_dist == k){
                break;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};