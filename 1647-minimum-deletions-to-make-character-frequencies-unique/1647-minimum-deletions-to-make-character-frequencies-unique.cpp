class Solution {
public:
    int minDeletions(string s) {
        int del = 0;
        vector<int> freq(26);
        for(char ch : s){
            freq[ch -'a']++;
        }
        
        set<int> st;
        for(int c : freq){
            while(c > 0 and st.count(c) > 0){
                del++;
                c--;
            }
            st.insert(c);
        }
        return del;
        
        
    }
};