class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]  == 1){
                    grid[i][j] = 0;
                    q.push({i,j});
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }
        int height = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                for(int d = 0; d < 4; d++){
                    int x = curr.first + dirs[d][0];
                    int y = curr.second + dirs[d][1];
                    if(x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == -1){
                        grid[x][y] = height;
                        q.push({x,y});
                    }
                }
            }
            height++;
        }
        return grid;
    }
};