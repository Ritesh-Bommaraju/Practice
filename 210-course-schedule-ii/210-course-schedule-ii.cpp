class Solution {
public:
    void topo(unordered_map<int, list<int>>& adj, int curr, vector<bool> &visited,stack<int>&st){
        visited[curr] = true;
        for(auto i : adj[curr]){
            if(!visited[i]){
                topo(adj, i, visited, st);
            }
        }
        st.push(curr);
    }
    
    
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
    
    
    
    bool cycle_check(unordered_map<int, list<int>>& adj, int n){
        vector<int> vis(n);
        vector<int> dfsvis(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bool check = dfs(i, vis, dfsvis, adj);
                if(check) return true;
            }
        }
        return false;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i < n; i++){
            int u = p[i][1];
            int v = p[i][0];
            adj[u].push_back(v);
        }
        if(cycle_check(adj, numCourses)){
            return {};
        }
        // topo sort;
        stack<int> st;
        vector<bool> visited(numCourses,false);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                topo(adj, i, visited, st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};