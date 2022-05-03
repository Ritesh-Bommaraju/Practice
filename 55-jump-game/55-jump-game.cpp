class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n = nums.size();
        // int reachable = 0;
        // for(int i = 0; i < n; i++){
        //     if(i > reachable){
        //         return false;
        //     }
        //     reachable = max(reachable, nums[i] + i);
        // }
        // return true;
        int lastgoodindex = nums.size()-1;
        for(int i = nums.size()-1; i>=0; i--){
            if(i + nums[i] >= lastgoodindex){
                lastgoodindex = i;
            }
        }
        if(lastgoodindex == 0){
            return true;
        }
        else{
            return false;
        }
    }
};