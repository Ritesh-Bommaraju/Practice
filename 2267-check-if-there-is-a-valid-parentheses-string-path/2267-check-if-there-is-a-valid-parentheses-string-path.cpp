class Solution {
public:
    int dp[100][100][205];
    bool helper(vector<vector<char>>& grid, int i, int j, int open){
        if(i >= grid.size() || j >= grid[0].size()){
            return false;
        }
        
        if(grid[i][j] == '('){
            open++;
        }
        else{
            open--;
        }
        if(open < 0){
            return false;
        }
        if(dp[i][j][open] != -1){
            return dp[i][j][open];
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            if(open == 0){
                return true;
            }
            else{
                return false;
            }
        }
        int next = helper(grid, i+1, j, open) || helper(grid, i, j+1, open);
        return dp[i][j][open] = next;
    }
    
    
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')'){
            return false;
        }
        memset(dp, -1, sizeof(dp));
        bool ans = helper(grid, 0, 0, 0);
        return ans;
    }
};