class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0; // 2's pointer
        int p3 = 0; // 3's pointer
        int p5 = 0; // 5's pointer
        for(int i = 1; i < n; i++){
            int p2Val = dp[p2] * 2;
            int p3Val = dp[p3] * 3;
            int p5Val = dp[p5] * 5;
            int currentUglyNumber = min(p2Val, min(p3Val, p5Val));
            /* 
                move the pointer(s) that produced the currentUglyNumber
                so we don't consider that value again
            */
            if (currentUglyNumber == p2Val) p2++;
            if (currentUglyNumber == p3Val) p3++;
            if (currentUglyNumber == p5Val) p5++;
            dp[i] = currentUglyNumber;
        }
        return dp[n-1];
        
    }
};