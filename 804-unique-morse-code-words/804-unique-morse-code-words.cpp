class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> mc = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set <string> f;
        for(string i: words){
            string v = "";
            for(char ch: i){
                v += mc[ch - 'a'];
            }
            f.insert(v);
        }
        return f.size();
    }
};