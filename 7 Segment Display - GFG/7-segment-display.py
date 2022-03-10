#User function Template for python3

class Solution:
    def sevenSegments(self, S, N):
        # code here 
        hmap = {}
        hmap[0] = 6
        hmap[1] = 2
        hmap[2] = 5
        hmap[3] = 5
        hmap[4] = 4
        hmap[5] = 5
        hmap[6] = 6
        hmap[7] = 3
        hmap[8] = 7
        hmap[9] = 5
        seg = 0
        for i in S:
            seg += hmap[int(i)]
        #print(seg)
        ans = []
        for i in range(N):
            ans .append ('1')
            seg-=2
        for j in range(N):
            if seg == 4:
                ans[j] = '0'
                break
            elif seg > 4:
                ans[j] = '0'
                seg-=4
            elif seg < 4:
                if seg == 3:
                    ans[-1] = '2'
                elif seg == 2:
                    ans[-1] = '4'
                elif seg == 1:
                    ans[-1] = '7'
                
        if seg > 0 :
            k= N-1
            while(seg and k >= 0):
                last = hmap[int(ans[k])]
                newseg = last+1
                if str(newseg) == '7':
                    ans[k] = '8'
                seg-=1
                N-=1
        ans = "".join(ans)
        return ans

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        S=input()
        
        ob = Solution()
        print(ob.sevenSegments(S,N))
# } Driver Code Ends