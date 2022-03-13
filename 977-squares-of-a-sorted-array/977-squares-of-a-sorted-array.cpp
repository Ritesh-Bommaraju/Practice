class Solution {
public:
    // int calculateSquare(int number)
    // {
    //     return number * number;
    // }
    // vector<int> sortedSquares(vector<int>& nums) {
    //     for(int i = 0; i < nums.size(); i++){
    //         nums[i] = calculateSquare(nums[i]);
    //     }
    //     sort(nums.begin(), nums.end());
    //     return nums;
    // }
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointer method
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());
        int pointer = nums.size() - 1;
        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                ans[pointer] = nums[left]*nums[left];
                left++;
            }
            else{
                ans[pointer] = nums[right]*nums[right];
                right--;
            }
            pointer--;
        }
        return ans;
    }
};