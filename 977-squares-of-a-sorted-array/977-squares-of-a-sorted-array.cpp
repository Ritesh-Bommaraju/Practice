class Solution {
public:
    int calculateSquare(int number)
    {
        return number * number;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = calculateSquare(nums[i]);
        }
        sort(nums.begin(), nums.end());
        return nums;
        
    }
};