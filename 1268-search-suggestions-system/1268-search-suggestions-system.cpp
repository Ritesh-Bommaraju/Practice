class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        string curr = "";
        vector<vector<string>> ans;
        for(auto c : searchWord){
            curr += c;
            set<string> s;
            for(auto p: products){
                if(p.substr(0,curr.size()) == curr){
                    s.insert(p);
                }
            }
            vector<string> temp;
            int count = 0;
            while(!s.empty()){
                if(count == 3){
                    break;
                }
                temp.push_back(*s.begin());
                s.erase(s.begin());
                count++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};