class Solution {
public:
    int balancedStringSplit(string s) {
        int res=0, ct=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='L'){ 
                ct--;
            }
            else{
                ct++;
            }
            if(ct==0){
                res++;
            }
        }
        return res;
    }
};