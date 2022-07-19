class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            string curr = words[i];
            if(curr == s.substr(0, curr.size())){
                count++;
            }
        }
        return count;
    }
};