class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == 1){
                return 2;
            }
            else{
                return 1;
            }
        }
        bool containsone = false;
        
        // for one it is an edge case
        
        // step 1 : remove all numbers out of the range 1->n
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                containsone = true;
            }
            if(nums[i] <= n && nums[i] >= 1){
                continue;
            }
            else{
                nums[i] = 1;
            }
        }
        if(containsone == false){
            return 1;
        }
        // make the given array as visited only 
        for(int i = 0; i < n; i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0){
                nums[idx] = -nums[idx];
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return n+1;
        
    }
};