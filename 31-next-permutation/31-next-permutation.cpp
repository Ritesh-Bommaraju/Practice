class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        reverse(temp.begin(), temp.end());
        int idx1 = -1;
        for(int i = 0; i<= n-2; i++){
            if(temp[i] > temp[i+1]){
                idx1 = i+1;
                break;
            }
        }
        if(idx1 != -1){
            int swap1 =  n - idx1 - 1;
            int idx2 = -1;
            int val1 = temp[idx1];
            for(int i = 0; i < n; i++){
                if(temp[i] > val1){
                    idx2 = i;
                    break;
                }
            }
            int swap2 = n - idx2 - 1;
            swap(nums[swap1], nums[swap2]);
            int ar = swap1 + 1;
            // cout << swap1 << " "<< swap2 << endl;
            // reverse(nums.begin() + ar, nums.begin() + n);
            reverse(nums.begin() + ar,  nums.begin() + n);
        }
        else{
            reverse(nums.begin(), nums.end());
        }
    }
};