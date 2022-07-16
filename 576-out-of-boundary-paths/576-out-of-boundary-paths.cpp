class Solution {
public:
    int mod = pow(10,9) + 7;
    int helper(int m, int n, int k, int sr, int sc, vector<vector<vector<int>>>& dp){
        if(k < 0){
            return 0;
        }
        if(sr < 0 || sc < 0 || sr >= m || sc >= n){
            return 1;
        }
        if(dp[k][sr][sc] != -1){
            return dp[k][sr][sc];
        }
        long right = helper(m,n,k-1,sr+1, sc, dp) % mod;
        long left = helper(m,n,k-1,sr, sc+1, dp) % mod;
        long down = helper(m,n,k-1,sr-1, sc, dp) % mod;
        long top = helper(m,n,k-1,sr, sc-1, dp) % mod;
        dp[k][sr][sc] = (right + left + down + top)%mod;
        return dp[k][sr][sc] % mod;
    }
    int findPaths(int m, int n, int k, int sr, int sc) {
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, -1)));
        dp[k][sr][sc] = helper(m,n,k,sr,sc,dp);
        return dp[k][sr][sc];
    }
    
};