class Solution {
public:
    bool helper(vector<int>& arr, int mid, int operations){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > mid){
                operations -= arr[i]/mid;
                if(arr[i] % mid == 0){
                    operations++;
                }
            }
        }
        if(operations >= 0){
            return true;
        }
        else{
            return false;
        }
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(helper(nums, mid, maxOperations)){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid + 1;
            }

        }
        return ans;
        
    }
};