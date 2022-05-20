class Solution {
public:
    int helper(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp, int m, int n){
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
        int right = helper(mat, i+1, j, dp, m, n);
        int bottom = helper(mat, i, j+1, dp, m, n);
        dp[i][j] = right + bottom;
        return dp[i][j];
    }
    
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int> > mat(m,vector<int>(n, 0));
        vector<vector<int> > dp(m,vector<int>(n,-1));
        int ans = helper(mat, 0, 0, dp, m, n);
        return ans;
    }
};