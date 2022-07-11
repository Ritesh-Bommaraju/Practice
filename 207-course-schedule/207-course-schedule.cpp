class Solution {
private:
    bool dfs(int node, vector<int> &vis, vector<int> &dfsvis, unordered_map<int, list<int>> &adj){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto i: adj[node]){
            if(!vis[i]){
                bool check = dfs(i, vis, dfsvis, adj);
                if(check) return true;
            }
            else if(dfsvis[i] == true){
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<p.size(); i++){
            int u = p[i][1];
            int v = p[i][0];
            adj[u].push_back(v);
        }
        vector<int> vis(n);
        vector<int> dfsvis(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bool check = dfs(i, vis, dfsvis, adj);
                if(check) return false;
            }
        }
        return true;
    }
};
