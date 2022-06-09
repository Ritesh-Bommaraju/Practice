class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int curr_sum = 0;
        int minLen = INT_MAX;
        while(right < nums.size()){
            curr_sum+= nums[right];
            
            if(curr_sum >= target){
                while(curr_sum >= target){
                    curr_sum -= nums[left];
                    left++;
                }
                minLen = min(minLen, (right - left + 1) + 1);
                // the additional + 1 because, in the while loop we do an extra left++, 
                // before checking 
            }
            right++;
        }
        if(minLen == INT_MAX){
            return 0;
        }
        return minLen;
    }
};