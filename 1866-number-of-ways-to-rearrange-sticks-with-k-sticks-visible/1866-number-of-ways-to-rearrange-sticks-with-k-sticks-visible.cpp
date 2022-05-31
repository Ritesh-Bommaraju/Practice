class Solution {
public:
    long long int dp[1001][1001];
    long long int mod = 1e9 + 7;
    
    long long int helper(int n,int k){
        if(n == 0 || k == 0){
            return 0;
        }if(n == k){
            return 1;
        }if(dp[n][k] != -1){
            return dp[n][k]%mod;
        }
        long long int first = (helper(n-1,k-1))%mod;
        long long int second = ((n-1)*helper(n-1,k))%mod;
        return dp[n][k] = (first+second)%mod;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(n,k);
    }
};