class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int start = 0;
        int next = 0;
        while(start < n){
            while(next < n and nums[next] - nums[start] <= k){
                next++;
            }
            ans++;
            start = next;
        }
        return ans;
    }
};