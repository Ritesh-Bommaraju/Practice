class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int org_sum = ((nums.size())*(nums.size() + 1))/2;
        int ans = org_sum - sum;
        return ans;
        
        
    }
};