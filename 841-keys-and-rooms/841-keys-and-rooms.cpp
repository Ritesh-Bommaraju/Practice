class Solution {
public:

    void helper(vector<vector<int>> &graph, int curr, vector<bool> &vis){
        vis[curr] = true;
        for(int i = 0; i < graph[curr].size(); i++){
            if(!vis[graph[curr][i]]){
                helper(graph, graph[curr][i], vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n, false);
        helper(rooms, 0, vis);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};