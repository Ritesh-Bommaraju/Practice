class Solution {
public:
    int minimumObstacles(vector<vector<int>>& mat) {
        vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                for(auto it : d){
                    int nx = x + it.first;
                    int ny = y + it.second;
                    if(nx >= 0 && ny>=0 && nx < n && ny < m && dp[x][y] + mat[nx][ny] < dp[nx][ny]){                
                        dp[nx][ny]=dp[x][y]+mat[nx][ny];
                        q.push({nx,ny});
                        }
                    }   
                }
        }
        return dp[n-1][m-1];
    }
};