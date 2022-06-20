class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
        n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n; i++){
            int pick = prev2 + nums[i];
            int nonpick = prev;
            
            prev2 = prev;
            prev = max(pick, nonpick);
            
        }
        return prev;
    }
};