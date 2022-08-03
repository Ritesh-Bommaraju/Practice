class Solution {
public:
    bool isright(vector<int>& nums, int idx){
        return nums[idx] <= nums[nums.size()-1];
    }
    
    int findMin(vector<int>& nums) {
        int low = -1;
        int high = nums.size() - 1;
        while(low + 1 < high){
            int mid = low + (high - low)/2;
            if(isright(nums, mid)){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return nums[high];
    }
};