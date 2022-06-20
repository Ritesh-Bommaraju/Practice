
// Sort all the words in descending order of their lengths.
// Initialise res with first word in the vector + "#"
// Now we just need to find, if other words in the vector + # are substring of res or not.
// if not, append that word to res.
bool compare(string &a,string &b){
    return a.length()>b.length();
}
class Solution {
public:
    
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(),words.end(),compare);
        string res="";
        res=res+words[0]+"#";
        
        for(int i=1;i<words.size();i++){
            
            int pos=res.find(words[i]+"#");
            if(pos!=-1)
                continue;
            else
                res+=words[i]+"#";
            
        }
        
        return res.length();
        
    }
};
// class Solution {
// public:
//     int minimumLengthEncoding(vector<string>& words) {
//         unordered_set<string> s;
//         for(string w : words){
//             s.insert(w);
//         }
//         for(string word : s){
//             for(int i = 1; i < word.size(); i++){
//                 // cout << word.substr(i) << endl;
//                 s.erase(word.substr(i));
//             }
//         }
//         // for(string ar : s){
//         //     cout << ar << " ";
//         // }
//         int ans = 0;
//         for(string ar : s){
//             ans += ar.size() + 1;
//         }
//         return ans;
//     }
// };