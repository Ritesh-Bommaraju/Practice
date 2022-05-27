class Solution {
public:
    int helper(int num, int dp[]){
        if(num == 0){
            return 0;
        }
        if(dp[num] != 0){
            return dp[num];
        }
        int op1, op2;
        op1 = op2 = INT_MAX; 
        if(num % 2 == 0){
            op1 = helper(num/2, dp) + 1;
        }
        op2 = helper(num-1, dp) + 1;
        dp[num] = min(op1,op2);
        return dp[num];
    }
    
    
    int numberOfSteps(int num) {
        int dp[1000000] = {0};
        return helper(num, dp);
    }
};