class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0;
        while(left + 1 < arr.size() && arr[left] <= arr[left+1]){
            left++;
        }
        if(left == arr.size() - 1){
            return 0;
        }
        int right = arr.size() - 1;
        while(right > left && arr[right] >= arr[right-1]){
            right--;
        }
        int temp = arr.size() - left - 1;
        int ans = min(temp, right);
        int i = 0;
        int j = right;
        while(i <= left && j < arr.size()){
            if(arr[i] <= arr[j]){
                ans = min(ans, j - i - 1);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};