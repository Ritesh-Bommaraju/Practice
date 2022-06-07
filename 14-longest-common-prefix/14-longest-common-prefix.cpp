class Solution {
public:
    string helper(string s1, string s2){
        if(s1.size() < s2.size()){
            swap(s1, s2);
        }
        string prefix = "";
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == s2[i]){
                prefix+=s1[i];
            }
            else{
                break;
            }
        }
        return prefix;
    }
    
    
    
    
    string longestCommonPrefix(vector<string>& strs) {
        string assumed = strs[0];
        for(int i = 1; i < strs.size(); i++){
            assumed = helper(assumed, strs[i]);
        }
        return assumed;
    }
};