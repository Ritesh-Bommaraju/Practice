// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        long long f[26] = {0};
        for(int i=0; i<S.length(); i++) f[S[i]-'a']++;
        
        long long res = 0;
        bool flag = false; // to find if duplicates are present in string
        
        for(int i=0; i<26; i++) {
            res += f[i]*(S.length()-f[i]);
            if(f[i] > 1) flag = true;
        }
        res /= 2;
        if(flag) res++;
        return res;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends