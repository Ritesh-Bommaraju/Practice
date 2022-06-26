class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> result;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum = sum + nums[j];
                result.push_back(sum);
            }
        }
        sort(result.begin(), result.end());
       
        long long sum = 0;
        left--;
        right--;
        while(left <= right){
            sum = sum + result[left];
            left++;
        }
        sum = sum%(1000000007);
        return sum;
    }
};