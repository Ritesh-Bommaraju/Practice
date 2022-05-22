class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if(n == 0 ) return 0;
        if(n == 1) return 1;
		//declaring boolean matrix to keep track to palindrome substrings
		// if substring S(i,j) is palindrome then mem[i][j] = true; else mem[i][j] = false;
        bool mem[n][n];
        memset(mem,false, sizeof(mem));
        int res = 0;//result that store number of palindrome substring 
		
		//for loop that mark substring of length = 1 as palindrome 
		// ["abc"] => ["a"],["b"],["c"] are palindrome
		//one more point is same substrinds are allowed
        for(int i = 0; i< n;i++){
            mem[i][i] = true;
            res++;
        }
		//for loop that mark substring of length = 2 as palindrome 
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]){
                mem[i][i+1] = true;
                res++;
            }
        }
		//for loop that mark substring of length from 3 to size of given string as palindrome 
        for(int length = 3;length<=n;length++){
            for(int i = 0; i < n-length+1;i++){
                int j = i + length - 1;
                if(mem[i+1][j-1] && s[i] == s[j]){
                    mem[i][j] = true;
                    res++;
                }
            }
        }
        return res;
        
    }
};