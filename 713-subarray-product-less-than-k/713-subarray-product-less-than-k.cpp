class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int prod = 1;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            prod = prod * nums[right];
            while(prod>= k and left <= right){
                prod = prod/nums[left];
                left++;
            }
            ans += (right - left +1);
        }
        return ans;
    }
};