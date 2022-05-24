class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0 || n == 1){
            return 0;
        }
        int i = 0;
        int j = 0;
        int k = 0;
        int ans = 0;
        // right to left;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                k++;
            }
            else if(s[i] == ')'){
                k--;
            }
            if(k == 0){
                ans = max(ans, i-j+1);
            }
            if(k < 0){
                k = 0;
                j = i + 1;
            }
        }
        
        // left to right
        k = 0;
        j = n-1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ')'){
                k++;
            }
            else if(s[i] == '('){
                k--;
            }
            if(k == 0){
                ans = max(ans, j - i + 1);
            }
            if(k < 0){
                k = 0;
                j = i - 1;
            }
        }
        return ans;
    }
};