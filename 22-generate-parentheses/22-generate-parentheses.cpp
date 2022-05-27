class Solution {
public:
    void helper(vector<string>& ans, string curr, int open, int close){
        if(close < open){
            // here open > close means, we are subracting from open and close
            // i.e 
            return;
        }
        if(open == 0 && close == 0){
            ans.push_back(curr);
            return;
        }
        if(open > 0){
            helper(ans, curr + '(', open-1, close);
        }
        if(close > 0){
            helper(ans, curr + ')', open, close-1);
        }
    }
    
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, n);
        return ans;
    }
};
