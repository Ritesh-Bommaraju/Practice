class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // first occurance;
        int s = 0;
        int e = nums.size() - 1;
        int res1 = -1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                res1 = mid;
                e = mid - 1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        
        int res2 = -1;
        s = 0;
        e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s)/2;
            if(nums[mid] == target){
                res2 = mid;
                s = mid + 1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        cout << res1 << " " << res2 << endl;
        if(res1 != -1 and res2 != -1){
            return {res1, res2};
        }
        else{
            return {-1, -1};
        }
    }
};