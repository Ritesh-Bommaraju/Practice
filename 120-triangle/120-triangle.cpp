class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i , int j, vector<vector<int>>& dp){
        if(i >= triangle.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int call_1 = triangle[i][j] + helper(triangle, i+1, j+1, dp);
        int call_2 = triangle[i][j] + helper(triangle, i+1, j, dp);
        
        return dp[i][j] = min(call_1, call_2);
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return helper(triangle, 0, 0, dp);
    }
};