class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k -= n;
        int idx = n-1;
        while(k > 0){
            res[idx] += min(25, k);
            idx--;
            k -= min(25,k);
        }
        return res;
        
    }
};