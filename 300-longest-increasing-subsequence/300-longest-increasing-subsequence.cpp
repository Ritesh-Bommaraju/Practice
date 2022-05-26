class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int idx, int prev){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[prev + 1] != -1){
            return dp[prev + 1];
        }
        int pick = 0;
        int dont_pick = helper(nums, idx + 1, prev);
        if(prev == -1 || nums[idx] > nums[prev]){
            pick = 1 + helper(nums, idx+1, idx);
        }
        dp[prev+1] = max(pick, dont_pick);
        return dp[prev+1];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(size(nums)+1, -1);
        return helper(nums, 0, -1);
    }
    
};