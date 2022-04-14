class Solution {
public:
    
    int rec(vector<int>& nums, int i, int j){
        if(i > j){
            return 0;
        }
        int choice1 = nums[i] + min(rec(nums,i+2,j), rec(nums,i+1, j-1));
        int choice2 = nums[j] + min(rec(nums,i+1,j-1), rec(nums,i, j-2));
        
        return max(choice1, choice2);
    }
    
    
    
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int best_score = rec(nums, 0, n-1);
        if(sum - best_score > best_score){
            return false;
        }
        return true;
    }
};