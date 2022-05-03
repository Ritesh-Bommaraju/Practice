class Solution {
public:
    int helper(vector<int>& nums ,vector<int>& dp, int curr){
        if(curr >= nums.size()-1){
            return 0;
        }
        if(dp[curr] != 10001){
            return dp[curr];
        }
        // explore all possible jump sizes from current position. Store & return min jumps required
        for(int i = 1; i <= nums[curr]; i++){
            dp[curr] = min(dp[curr], 1 + helper(nums, dp, curr + i));
        }
        return dp[curr];
        
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 10001);
        int ans = helper(nums, dp, 0);
        return ans;
    }
};