class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n,'a');
        k -= n;
        int idx = n-1;
        while(k > 0){
            // cout << res[idx] << " " << k<< endl;
            res[idx] += min(25, k);
            // cout << res[idx] << endl;
            idx--;
            k -= min(25,k);
            // cout << k << endl;
        }
        return res;
        
    }
};