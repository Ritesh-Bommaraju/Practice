class Solution {
public:
    string removeDuplicates(string s) {
        stack<pair<char,int>> st;
        for(auto &c :s){
            if(!st.size() || st.top().first!=c){    
                st.push({c,1});
            }
            else{
                st.push({c,st.top().second+1});
                if(st.top().second>=2){
                    int i=st.top().second;
                    while(i--){
                        st.pop();
                    }
                }
            }
        }
        string ans ="";
        while(st.size()){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};