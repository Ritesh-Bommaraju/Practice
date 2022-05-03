class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int lr = nums[0];
        int end = -1;
        for(int i = 0; i < n; i++){
            if(lr>nums[i]){
                end = i;
            }
            else{
                lr = nums[i];
            }
        }
        int rl = nums[n-1];
        int start = 0;
        for(int i = n-2; i >= 0; i--){
            if(rl < nums[i]){
                start = i;
            }
            else{
                rl = nums[i];
            }
        }
        return end - start + 1;
    }
};