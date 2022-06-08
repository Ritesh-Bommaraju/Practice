class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        
        bool dp[2000][2000] = {false};
        for (int i = 0; i < n; ++i){
            dp[i][i] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                }
            }
        }
        
        // check 
        for(int i = 1; i < n - 1; i++){
            for(int j = i; j < n - 1; j++){
                if(dp[0][i-1] and dp[i][j] and dp[j+1][n-1]){
                    return true;
                }
            }
        }
        return false;
    }
};