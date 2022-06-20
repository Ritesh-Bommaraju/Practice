class Solution {
public:
    int n;
    int helper(vector<int>&nums,int curr, vector<int>& dp){
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr] != -1){
            return dp[curr];
        }
        return dp[curr] = max( (nums[curr] + helper(nums, curr + 2, dp)) ,helper(nums, curr+1,dp));
        
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n+1,-1);
        return helper(nums,0,dp);
    }
//     int rob(vector<int>& nums) {
//         int prev = 0, prev2 = 0, curr = 0;
//         for(int a : nums){
//             curr = max(prev, prev2 + a);
//             prev2 = prev;
//             prev = curr;
//         }
//         return curr;
//     }
};