class Solution {
public:
    int helper(vector<int> &arr, int target, int idx, int curr_sum) {
	if (idx < 0 && curr_sum == target) {
		return 1;
	}
	if (idx < 0) {
		return 0;
	}
	int pos = helper(arr, target, idx - 1, curr_sum + arr[idx]);
	int neg = helper(arr, target, idx - 1, curr_sum - arr[idx]);

	return pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, target, nums.size() - 1, 0);
    }
};