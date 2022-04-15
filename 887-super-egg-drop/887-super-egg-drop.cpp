// class Solution {
// public:
//     int superEggDrop(int eggs, int floors) {
//         vector<vector<int>> dp(eggs+1, vector<int>(floors+1, 0));
//         for(int i = 1; i <= eggs; i++){
//             for(int j = 1; j<=floors; j++){
//                 if(i==1){
//                     dp[i][j] = j;
//                 }
//                 else if(j==1){
//                     dp[i][j] = 1;
//                 }
//                 else{
//                     int minimum = INT_MAX;
//                     for(int mj = j-1, pj = 0; mj>=0; mj--, pj++){
//                         int val1 = dp[i][mj];
//                         int val2 = dp[i-1][pj];
//                         int worst_case = max(val1, val2); // choosing the worst thing
//                         minimum = min(minimum, worst_case); // best of worst till now
//                     }
//                     dp[i][j] = minimum + 1;   
//                 }
//             }
//         }
//         return dp[eggs][floors];
//     }
// };
class Solution {
public:
    int dp[10001][101];
    
    int func(int f , int e)
    {
         //base case	 
          if(f==0 || f==1)
            return f;  
        if(e==1)
            return f;
        
         if(dp[f][e]!=-1)
             return dp[f][e];
         
        int ans=INT_MAX;
        
        int lo=1 , h=f;
        
        while(lo<h)
        {
            int mid= (lo + (h-lo)/2);
            int val1 = func(mid-1 , e-1 );
            int val2 = func(f-mid , e);
            
            int temp= 1 + max(val1 , val2);
            if(val1>val2)
            
                h=mid;
            
            else
            
                lo=mid+1;
            
            
            ans = min( ans , temp);
            
            
        }
        
        return dp[f][e]=ans;
        
        
        
    }
    int superEggDrop(int e, int f) {
        memset(dp , -1 , sizeof(dp));
        
        return func(f , e);
        
    }
    
};