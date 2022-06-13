class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {0};
        }
        vector<int> degrees(n,0);
        vector<vector<int>>G(n);
        for(int i=0;i<edges.size();i++)
        {
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][1]]++;
            degrees[edges[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(degrees[i]==1){ 
                //adding all the leave nodes
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            int size = q.size();
            while(size--){
                int cur= q.front();
                q.pop();
                ans.push_back(cur);
                for(auto &neighbor:G[cur]){
                    degrees[neighbor]--;
                    if(degrees[neighbor] == 1){
                        q.push(neighbor);
                    }
                }
            }
        }
        return ans;
    }
};