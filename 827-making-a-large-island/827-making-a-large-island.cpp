class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int region){
        if( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1 ){
            return 0;
        }
        grid[i][j] = region;
        int sum = 1;
        sum += dfs(grid, i+1, j, region);
        sum += dfs(grid, i, j+1, region);
        sum += dfs(grid, i-1, j, region);
        sum += dfs(grid, i, j-1, region);
        return sum;
    }
    
    
    
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> regions_area;
        regions_area.insert({0,0}); // handles the all 0 case;
        int region = 2;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j, region);
                    regions_area.insert({region, area});
                    region++;
                }
            }
        }
        int max_area = INT_MIN;
        for (const auto &entry: regions_area){
            if (max_area < entry.second){
                max_area = entry.second;
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    set<int> neighbours;
                    for(auto x : dirs){
                        int new_i = i + x.first;
                        int new_j = j + x.second;
                        if( new_i >= 0 and new_i < grid.size() and new_j >= 0 and new_j < grid[0].size() and grid[new_i][new_j] != 0){
                            neighbours.insert(grid[new_i][new_j]);
                        }
                        int area = 0;
                        for(int ar : neighbours){
                            area += regions_area.at(ar);
                        }
                        if(area + 1 > max_area){
                            max_area = area + 1;
                        }
                    }
                }
            }
        }
        return max_area;
        
        
    }
    
};