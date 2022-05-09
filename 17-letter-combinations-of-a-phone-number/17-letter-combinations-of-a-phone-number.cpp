class Solution {
public:
    void helper(vector<string>& ans, string digits, vector<string>& keypad, int index, string curr_string){
        // if the index we reach is equal to the length of the given digits string length, i.e we exhausted the whole string so we append it to the ans vector
        if(index == digits.size()){
            ans.push_back(curr_string);
            return;
        }
        // we extract the correct index of the digit we are correctly in and extract the value at that index in the keypad vector;
        int d = digits[index] - '0';
        for(char ch : keypad[d]){
            // we increment the index by 1 and add the char to the current string
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