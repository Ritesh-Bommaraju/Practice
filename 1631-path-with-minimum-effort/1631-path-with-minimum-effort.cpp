class Solution {
public:
//     int m, n;
//     int vis[105][105];
//     vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0, -1}, {0, 1}};
    
//     void dfs(vector<vector<int>>&heights, int i, int j, int threshold){
//         if(!vis[i][j]){
//             vis[i][j] = 1;
//             for(int x = 0; x < 4; x++){
//                 int new_x = i + dirs[i].first;
//                 int new_y = j + dirs[i].second;
//                 if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m){
//                     continue;
//                 }
//                 if(abs(heights[i][j] - heights[new_x][new_y]) <= threshold){
//                     dfs(heights, new_x, new_y, threshold);
//                 }   
//             }
//         } 
//     }
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         // binary search
//         int left = 0;
//         int right = 1e9+2;
//         m = heights[0].size();
//         n = heights.size();
//         while(left < right){
//             int mid = (left + right)/2;
//             memset(vis, 0, sizeof(vis));
//             dfs(heights, 0, 0, mid);
//             if(vis[n-1][m-1] == 1){
//                 right = mid;
//             }
//             else{
//                 left = mid +1;
//             }
//         }
//         return left;
//     }
    
    int vis[105][105];
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
    
    void ok(int x, int y,int mid , vector<vector<int>>& heights){
        if(!vis[x][y]){
            vis[x][y]=1;
            int n=heights.size();
            int m=heights[0].size();
            for(int i=0;i<4;i++){
                int X=x+dir[i].first;
                int Y=y+dir[i].second;
                if(X<0 || X>=n || Y<0 || Y>=m)
                    continue;
                if(abs(heights[x][y]-heights[X][Y])<=mid)
                    ok(X,Y,mid,heights);
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0,r=1e9+2;
        int n=heights.size();
        int m=heights[0].size();
        while(l<r){
            int mid=(l+r)/2;
            memset(vis,0,sizeof(vis));
            ok(0,0,mid,heights);
            if(vis[n-1][m-1]==1)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
};