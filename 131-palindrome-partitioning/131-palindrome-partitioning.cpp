class Solution {
public:
    vector<vector<string>> ans;
    
    bool ispalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void helper(string s, vector<string> &comb, int index){
        if(s.size() == index){
            ans.push_back(comb);
            return;
        }
        for(int i = index; i < s.size(); i++){
            // cout << index << " " << i << endl;
            // cout << s.substr(index, i - index + 1) << endl;
            if(ispalindrome(s, index, i)){
                comb.push_back(s.substr(index, i - index + 1));
                helper(s, comb, i+1);
                comb.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> comb;
        helper(s, comb,0);
        return ans;
    }
    //The Idea is simple: loop through the string, check if substr(0, i) is palindrome. If it is, recursively call dfs() on the rest of sub string: substr(i+1, length). keep the current palindrome partition so far in the 'path' argument of dfs(). When reaching the end of string, add current partition in the result.
    
};