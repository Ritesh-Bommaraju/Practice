class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int find = total - x;
        if(x > total){
            return -1;
        }
        int i = 0;
        int j = 0;
        int curr_sum = 0;
        int max_len = INT_MIN;
        while(j < nums.size()){
            curr_sum += nums[j];
            while(curr_sum > find){
                curr_sum -= nums[i];
                i++;
            }
            if(curr_sum == find){
                max_len = max(max_len, (j - i + 1));
            }
            j++;
        }
        if(max_len == INT_MIN){
            return -1;
        }
        return nums.size() - max_len;
    }
};