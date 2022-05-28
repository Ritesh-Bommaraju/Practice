class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // int left = 0;
        // while(left + 1 < arr.size() && arr[left] <= arr[left+1]){
        //     left++;
        // }
        // if(left == arr.size() - 1){
        //     return 0;
        // }
        // int right = arr.size() - 1;
        // while(right > left && arr[right] >= arr[right-1]){
        //     right--;
        // }
        // int temp = arr.size() - left - 1;
        // int ans = min(temp, right);
        // int i = 0;
        // int j = right;
        // while(i <= left && j < arr.size()){
        //     if(arr[i] <= arr[j]){
        //         ans = min(ans, j - i - 1);
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }
        // return ans;
        int n = arr.size();
        int l = 0, r = n - 1;
        int res = n;
        
        while (r - 1 >= 0 && arr[r - 1] <= arr[r]) {
            r--;
        }
        
        res = r;
        
        while (l < r && (l == 0 || arr[l - 1] <= arr[l])) {
            while (r < n && arr[l] > arr[r]) {
                r++;
            }
            
            res = min(res, r - l - 1);
            l++;
        }
        
        return res;
    }
};