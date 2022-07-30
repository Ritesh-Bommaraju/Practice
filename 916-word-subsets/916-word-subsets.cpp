class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<int> w2_freq(26, 0);
        for(auto x : w2){
            vector<int> temp(26,0);
            for(auto c : x){
                temp[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                w2_freq[i] = max(w2_freq[i], temp[i]);
            }
        }
        vector<string> ans;
        for(auto x : w1){
            vector<int> curr(26,0);
            for(auto c : x){
                curr[c - 'a']++;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(curr[i] < w2_freq[i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans.push_back(x);
            }
            
        }
        return ans;
    }
};