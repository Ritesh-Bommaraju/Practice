class Solution {
public:
    bool helper(string &s1, string s2){
        int j = 0;
        for(int i = 0; i < s1.size() && j < s2.size(); i++){
            if(s1[i] == s2[j]){
                j++;
            }
        }
        if(j == s2.size()){
            return true;
        }
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto w: words){
            mp[w]++;
        }
        int count = 0;
        for(auto x : mp){
            if(helper(s, x.first)){
                count = count + x.second;
            }
        }
        return count;
    }
};
