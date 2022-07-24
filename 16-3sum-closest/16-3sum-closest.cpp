class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        if(nums.size() < 3){
            return res;
        }
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n; i++){
            int low = i + 1;
            int high = n-1;
            while(low < high){
                int curr = nums[i] + nums[low] + nums[high];
                if(abs(ans-target) > abs(curr - target)){
                    ans = curr;
                }
                if(curr == target){
                    return target;
                    break;
                }
                if(curr > target){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return ans;
    }
};