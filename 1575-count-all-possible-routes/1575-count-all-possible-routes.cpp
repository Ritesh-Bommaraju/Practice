class Solution {
public:
    int mod = 1000000007;
    int helper(int start, int finish, int fuel, vector<int>& locations, vector<vector<int>>& dp){
        if(fuel < 0){
            return 0;
        }
        int ans = 0;
        if(start == finish){
            ans++;
        }
        if(dp[start][fuel] != INT_MAX){
            return dp[start][fuel];
        }
        for(int i = 0; i < locations.size(); i++){
            if(i == start || abs(locations[i] - locations[start]) > fuel){
                continue;
            }
            ans += helper(i, finish, fuel - abs(locations[i] - locations[start]), locations, dp);
            ans = ans % mod;
        }
        return dp[start][fuel] = ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int>(fuel+1, INT_MAX));
        int ans = helper(start, finish, fuel, locations, dp);
        return ans;
    }
};