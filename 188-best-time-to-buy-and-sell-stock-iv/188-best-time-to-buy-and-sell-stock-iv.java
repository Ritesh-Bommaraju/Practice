class Solution {
    // Top-Down
    public int maxProfit(int k, int[] prices) {
        if (k * 2 >= prices.length) {
            return maxProfit2(prices);
        }
        int[][][] dp = new int[1000][101][2];
        return dfs(prices, 0, k, true, dp);
    }
    
    public int maxProfit2(int[] prices) {
        int res = 0;
        for (int i = 1; i < prices.length; ++i) 
            res += Math.max(0, prices[i] - prices[i - 1]);
        return res;
    }
    
    public int dfs(int[] prices, int p, int k, boolean buy, int[][][] dp) {
        if (p >= prices.length || (k == 0 && buy))
            return 0;
        
        int buyIdx = (buy ? 1: 0);
        
        if (dp[p][k][buyIdx] == 0)
            dp[p][k][buyIdx] = Math.max(dfs(prices, p + 1, k, buy, dp), 
                (buy ? -1 : 1) * prices[p] + dfs(prices, p + 1, k - buyIdx, !buy, dp));
        return dp[p][k][buyIdx];
    }
}