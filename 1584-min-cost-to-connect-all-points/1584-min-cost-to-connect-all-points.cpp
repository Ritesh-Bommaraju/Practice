class Solution {
public:
    // kruskal implementation 
    int findParent(int i,vector<int>&parent){
        if(parent[i] < 0){
            return i;
        }
        return parent[i]=findParent(parent[i],parent);
    }
    
    void uni(int i,int j,vector<int>&parent){
        parent[i]=j;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n  = points.size();
        vector<int> parents(n,-1);
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int manhattan=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);  
                edges.push_back({manhattan,{i,j}});
            }
        }
        sort(edges.begin(), edges.end());
        int ans=0;
        for(int i=0;i<edges.size();i++){
            int a=findParent(edges[i].second.first, parents);
            int b=findParent(edges[i].second.second, parents);   
            if(a!=b){
                ans+=edges[i].first;
                uni(a,b,parents);
            }
        }
        return ans;
    }
};