class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>&graph, int n, int curr, vector<int>&path){
        if(curr == n-1){
            ans.push_back(path);
            return;
        }
        for(int a : graph[curr]){
            path.push_back(a);
            dfs(graph, n, a, path);
            path.pop_back();
        }
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        path.push_back(0);
        dfs(graph, n, 0, path);
        return ans;
        
    }
};