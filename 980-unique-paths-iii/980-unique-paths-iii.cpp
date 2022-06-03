class Solution {
public:
    int ans = 0;
    bool isValidCell(vector<vector<int>>& G, int i, int j) {
        return i >= 0 && j >= 0 && i < size(G) && j < size(G[0]) && G[i][j] != -1 && G[i][j] != 3;
    }
    void dfs(int i ,int j ,vector<vector<int>>& grid, int can_walk_over){
        if(isValidCell(grid, i,j) == false){
            return;
        }
        if(grid[i][j] == 2) {                    
            if(can_walk_over == 0){
                ans++;
            }
            return;                          
        }
        grid[i][j] = 3;
        dfs(i+1, j, grid, can_walk_over - 1);
        dfs(i, j+1, grid, can_walk_over - 1);
        dfs(i-1, j, grid, can_walk_over - 1);
        dfs(i, j-1, grid, can_walk_over - 1);
        grid[i][j] = 0;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr, sc;
        int can_walk_over = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    sr = i;
                    sc = j;
                }
                else if(grid[i][j] != -1){
                    can_walk_over++;
                }
            }
        }
        dfs(sr, sc, grid, can_walk_over);
        return ans;
    }
};