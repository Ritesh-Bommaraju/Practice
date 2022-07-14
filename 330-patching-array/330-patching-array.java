class Solution {
    public int minPatches(int[] nums, int n) {
        int n1 = nums.length;
        long sum = 1;
        int cnt = 0;
        int i=0;
        while(sum <= n){
            if(i < n1 && nums[i] <= sum){
                sum += nums[i++];
            }
            else{
                sum+=sum;
                cnt++;
            }
        }
        return cnt;
    }
}