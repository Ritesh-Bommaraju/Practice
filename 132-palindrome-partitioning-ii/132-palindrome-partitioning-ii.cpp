class Solution {
public:
    bool ispalindrome(string& s, int st, int en){
        while(st <= en){
            if(s[st] != s[en]){
                return false;
            }
            st++;
            en--;
        }
        return true;
    }
    
    
    int helper(int start, string &s, vector<int>&dp){
        if(start == s.size()){
            return 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        int min_cost = INT_MAX;
        for(int i = start; i < s.size(); i++){
            if(ispalindrome(s,start, i)){
                int cost = 1 + helper(i+1, s, dp);
                min_cost = min(cost, min_cost);
            }
        }
        return dp[start] = min_cost;
    }
    
    
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        int ans = helper(0,s, dp);
        return ans - 1;
    }
};