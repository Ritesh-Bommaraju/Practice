#User function Template for python3

class Solution:
    def arrangeString(self, s):
        nums = ['0','1','2','3','4','5','6','7','8','9']
        l = list(s)
        ans = 0
        alpha = []
        for i in l:
            if i in nums:
                ans += int(i)
            else:
                alpha.append(i)
        alpha.sort()
        alpha.append(str(ans))
        return "".join(alpha)
                
        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.arrangeString(s)
        print(ans)
# } Driver Code Ends