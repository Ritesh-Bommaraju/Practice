class Solution {
public:
    long prod=INT_MIN;
    long mod=1000000007;
    int maxProductPath(vector<vector<int>>& grid) {
        dfs(grid,0,0,grid.size()-1,grid[0].size()-1,1);
        if(prod<0)
            return -1;
        return prod%mod;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,long prod1){
        if(i==m && j==n){
            prod1 =(prod1*grid[i][j]);
            prod=max(prod,prod1);
            return;
        }
        if(grid[i][j]==0){
            prod=max(prod,(long)0);
            return;
        }
        prod1 = (prod1*grid[i][j]);
        // cout << grid[i][j] << " ";
        if(i+1<=m){
            dfs(grid,i+1,j,m,n,prod1);
        }
        if(j+1<=n){
            dfs(grid,i,j+1,m,n,prod1);
        }
    }
};