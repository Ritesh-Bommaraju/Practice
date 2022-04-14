class Solution {
public:
    int rec(vector<int>& nums, int i, int j, vector<vector<int>>&dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int choice1 = nums[i] + min(rec(nums,i+2,j,dp), rec(nums,i+1, j-1,dp));
        int choice2 = nums[j] + min(rec(nums,i+1,j-1,dp), rec(nums,i, j-2,dp));
        
        return dp[i][j] = max(choice1, choice2);
    }
    
    
    
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int best_score = rec(nums, 0, n-1,dp);
        if(sum - best_score > best_score){
            return false;
        }
        return true;
    }
};