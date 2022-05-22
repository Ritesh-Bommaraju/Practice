class Solution {
public:
    vector<int> par;
    
    int find(int x){
        if(par[x] == -1){
            return x;
        }
        return find(par[x]);
    }
    
    void _union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        if(p1 != p2){
            par[p2] = p1;
        }
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.resize(edges.size() + 1, -1);
        
        for(int i = 0; i < edges.size(); i++){
            int p1 = find(edges[i][0]);
            int p2 = find(edges[i][1]);
            if(p1 == p2){
                return {edges[i][0], edges[i][1]};
            }
            _union(edges[i][0], edges[i][1]);
        }
        return {};
    }
};