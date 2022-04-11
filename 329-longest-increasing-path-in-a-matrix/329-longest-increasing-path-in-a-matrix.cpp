class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), 0));
        int Max = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                Max = max(Max, helper(matrix, i, j, memo));
            }
        }
        return Max;
    }
    
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        if(memo[i][j] > 0){
            return memo[i][j];
        }
        int curr_max = 1;
        //down -- i+1, j
        if(i+1 < matrix.size() && i+1 >= 0 && matrix[i+1][j] > matrix[i][j]){
            curr_max = max(curr_max, 1+helper(matrix, i+1, j, memo));
        }
        //right -- i, j+1
        if(j+1 < matrix[0].size() && j+1 >= 0 && matrix[i][j+1] > matrix[i][j]){
            curr_max = max(curr_max, 1+helper(matrix, i, j+1, memo));
        }
        // top -- i-1, j
        if(i-1 < matrix.size() && i-1 >= 0 && matrix[i-1][j] > matrix[i][j]){
            curr_max = max(curr_max, 1+helper(matrix, i-1, j, memo));
        }
        //left -- i, j-1
        if(j-1 < matrix[0].size() && j-1 >= 0 && matrix[i][j-1] > matrix[i][j]){
            curr_max = max(curr_max, 1+helper(matrix, i, j-1, memo));
        }
        memo[i][j] = curr_max;
        return curr_max;
    }
};