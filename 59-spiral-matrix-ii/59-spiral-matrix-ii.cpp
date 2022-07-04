class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,-1));
        int count = 1;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int top = 0;
        int direction = 1;
        while(left <= right && top <= bottom){
            if(direction == 1){
                for(int i = left; i <= right; i++){
                    ans[top][i] = count;
                    count++;
                }
                top++;
                direction = 2;
            }
            else if(direction == 2){
                for(int i = top; i <= bottom; i++){
                    ans[i][right] = count;
                    count++;
        
                }
                right--;
                direction = 3;
            }
            else if(direction == 3){
                for(int i = right; i >= left; i--){
                    ans[bottom][i] = count;
                    count++;
                }
                bottom--;
                direction = 4;
            }
            else if(direction == 4){
                for(int i = bottom; i>= top; i--){
                    ans[i][left] = count;
                    count++;
                }
                left++;
                direction = 1;
            }
        }
        return ans;
    }
};