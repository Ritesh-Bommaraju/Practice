class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0;
        int maxTillNow = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};