class Solution {
public:
    int helper(int n, vector<int>& dp){
        if(n == 1){
            dp[n] = 1;
            return 1;
        }
        if(n == 2){
            dp[n] = 2;
            return 2;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int onestep = helper(n-1, dp);
        int twosteps = helper(n-2, dp);
        dp[n] = onestep + twosteps;
        return dp[n];
    }
    
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
        
    }
};
