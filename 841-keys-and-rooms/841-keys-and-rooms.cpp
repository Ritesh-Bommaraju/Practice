// class Solution {
// public:

//     void helper(vector<vector<int>> &graph, int curr, vector<bool> &vis){
//         vis[curr] = true;
//         for(int i = 0; i < graph[curr].size(); i++){
//             if(!vis[graph[curr][i]]){
//                 helper(graph, graph[curr][i], vis);
//             }
//         }
//     }

//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         int n=rooms.size();
//         vector<bool> vis(n, false);
//         helper(rooms, 0, vis);
//         for(int i = 0; i < n; i++){
//             if(!vis[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;
            for (int k : rooms[curr]){
                if (visited[k] == false){
                    q.push(k);
                }   
            } 
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
        
    }
};