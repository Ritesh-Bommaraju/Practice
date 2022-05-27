class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1){
            return s;
        }
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        string ans;
        for(int gap = 0; gap < s.size(); gap++){
            for(int i = 0, j = gap; j < s.size(); i++, j++){
                    if(gap == 0){
                        dp[i][j] = true;
                    }
                    else if(gap == 1){
                        if(s[i] == s[j]){
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = false;
                        }
                    }
                    else{
                        if(s[i] == s[j] && dp[i+1][j-1] == true){
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = false;
                        }
                    }
            }
        }
        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==true and j-i+1>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
    }
};