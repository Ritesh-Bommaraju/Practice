class Solution:
    def longestPalindrome(self, l: List[str]) -> int:
        mp = dict();
        res = 0;
        for i in l:
            rev = i[::-1]
            if(rev in mp and mp[rev] > 0):
                res+=4;
                mp[rev] -=1; 
            else:
                if i not in mp:
                    mp[i] = 1;
                else:
                    mp[i] += 1;

        for w, c in mp.items():
            if c == 1 and w[0] == w[1]:
                res+=2;
                break
        return res
        