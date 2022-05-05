class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 2){
            return *max_element(nums.begin(), nums.end());
        }
        int prev = 0, prev2 = 0, curr = 0;
        // considering last element
        for(int i = 1; i < nums.size(); i++){
            curr = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = curr;
        }
        int prev_ = 0, prev2_ = 0, curr_ = 0;
        // considering 1st element
        for(int i = 0; i < nums.size()-1; i++){
            curr_ = max(prev_, prev2_ + nums[i]);
            prev2_ = prev_;
            prev_ = curr_;
        }
        return max(curr, curr_);
    }
};