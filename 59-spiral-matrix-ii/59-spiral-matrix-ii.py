class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        c=1;
        l=[[0 for i in range(n)]for j in range(n)]
        for layer in range((n+1)//2):
            for i in range(layer,n-layer):
                l[layer][i]=c
                c=c+1
            for i in range(layer+1,n-layer):
                l[i][n-layer-1]=c
                c=c+1
            for i in range(n-layer-2,layer-1,-1):
                l[n-layer-1][i]=c
                c=c+1
            for i in range(n-layer-2,layer,-1):
                l[i][layer]=c
                c=c+1
        return l
        