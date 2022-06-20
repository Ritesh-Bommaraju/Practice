class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s;
        for(string w : words){
            s.insert(w);
        }
        for(string word : s){
            for(int i = 1; i < word.size(); i++){
                // cout << word.substr(i) << endl;
                s.erase(word.substr(i));
            }
        }
        // for(string ar : s){
        //     cout << ar << " ";
        // }
        int ans = 0;
        for(string ar : s){
            ans += ar.size() + 1;
        }
        return ans;
    }
};