class Solution {
public:
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     if(n == 1){
    //         return s;
    //     }
    //     vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    //     string ans;
    //     for(int gap = 0; gap < s.size(); gap++){
    //         for(int i = 0, j = gap; j < s.size(); i++, j++){
    //                 if(gap == 0){
    //                     dp[i][j] = true;
    //                 }
    //                 else if(gap == 1){
    //                     if(s[i] == s[j]){
    //                         dp[i][j] = true;
    //                     }
    //                     else{
    //                         dp[i][j] = false;
    //                     }
    //                 }
    //                 else{
    //                     if(s[i] == s[j] && dp[i+1][j-1] == true){
    //                         dp[i][j] = true;
    //                     }
    //                     else{
    //                         dp[i][j] = false;
    //                     }
    //                 }
    //         }
    //     }
    //     int max = 0;
    //     string maxstr = "";
    //     for(int i=0;i<n;i++){
    //         for(int j=i;j<n;j++){
    //             if(dp[i][j]==true and j-i+1>max){
    //                 max = j-i+1;
    //                 maxstr = s.substr(i,j-i+1);
    //             }
    //         }
    //     }
    //     return maxstr;
    // }
    string longestPalindrome(string s) {
        if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
        
    }
};