class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string res = "";
        vector<char> chars(n);
        for(int i = 1; i <= n; i++){
            chars[i-1] = '0' + i;
        }
        // for(int i = 0; i < chars.size(); i++){
        //     cout << chars[i] << endl;
        // }
        int pos;
        k = k - 1; // adjusting for 1 based indexing
        while (n) {
            pos = k / fact[n-1];
            res += chars[pos];
            chars.erase(begin(chars) + pos);
            k %= fact[n-1];
            n--;
        }
        return res;
        
    }
};