class Solution {
public:
    void helper(vector<string>& ans, string digits, vector<string>& keypad, int index, string curr_string){
        if(index == digits.size()){
            ans.push_back(curr_string);
            return;
        }
        int d = digits[index] - '0';
        for(char ch : keypad[d]){
            helper(ans, digits, keypad, index + 1, curr_string + ch);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        } 
        vector<string> keypad = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        helper(ans, digits, keypad, 0, "");
        return ans;
    }
};