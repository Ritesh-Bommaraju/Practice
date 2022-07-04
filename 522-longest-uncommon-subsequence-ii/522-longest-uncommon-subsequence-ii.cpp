class Solution {
public:
    bool helper(string& s1, string& s2){
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        if(i == s1.size()){
            return true;
        }
        return false;
    }
    
    int findLUSlength(vector<string>& strs) {
        // sorting by longest length first and ala
        sort(strs.begin(), strs.end(), []
    (const std::string& first, const std::string& second){
        return first.size() > second.size();
    });
        for(int i = 0; i < strs.size(); i++){
            bool found = false;
            for(int j = 0; j < strs.size(); j++){
                if(i == j){
                    continue;
                }
                found = helper(strs[i], strs[j]);
                if(found == true){
                    break;
                }
            }
            if(found == false){
                return strs[i].size();
            }
        }
        return -1;
    }
};