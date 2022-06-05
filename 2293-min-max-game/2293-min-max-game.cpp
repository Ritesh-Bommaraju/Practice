class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1){ // Base case
            return nums[0]; 
        }
        vector<int> newNum(n/2); 
        for(int i = 0; i < n/2; i++) { 
            if(i%2==0){ // even index case
                newNum[i] = min(nums[2 * i], nums[2 * i + 1]); 
            }
            else{ // odd index case
                newNum[i] = max(nums[2 * i], nums[2 * i + 1]); 
            }
        } 
        int ans = minMaxGame(newNum); // Recursive call for the new array
        return ans;
    }
};