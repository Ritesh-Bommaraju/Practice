class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> s;
        for(auto x : words){
            s.insert(x);
        }
        string ans = "";
        for(string w : words){
            if(w.size() > ans.size() or w.size() == ans.size() && ans > w){
                bool flag = true;
                for(int i = 1; i < w.size(); i++){
                    if(s.find(w.substr(0,i)) == s.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    ans = w;
                }
            }
        }
        return ans;
    }
};