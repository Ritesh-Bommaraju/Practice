class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string ar : strs){
            string temp = ar;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(ar);
        }
        vector<vector<string>> ans;
        for(auto p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};