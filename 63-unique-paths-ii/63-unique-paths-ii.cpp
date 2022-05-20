class Solution {
public:
    int m, n;
    int helper(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }
        if(mat[i][j] == 1){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = helper(mat, i+1, j, dp);
        int bottom = helper(mat, i, j+1, dp);
        dp[i][j] = right + bottom;
        return dp[i][j];
    }
    
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        int ans = helper(mat, 0, 0, dp);
        return ans;
    }
};