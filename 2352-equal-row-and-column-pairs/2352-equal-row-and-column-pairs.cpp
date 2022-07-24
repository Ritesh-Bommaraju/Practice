class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        map<vector<int>, int> mp;
        for(int i = 0; i < n; i++){
            mp[grid[i]]++;
        }
        for(int i = 0; i < n; i++){
            vector<int> curr_col;
            for(int j = 0; j < n; j++){
                curr_col.push_back(grid[j][i]);
            }
            if(mp.find(curr_col) != mp.end()){
                ans+= mp[curr_col];
            }
        }
        return ans;
        
    }
};
