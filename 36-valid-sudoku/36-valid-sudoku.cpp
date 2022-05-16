class Solution {
public:
    bool helper(vector<vector<char>>& board, int i, int j){
        int temp = board[i][j];
        int count = 0;
        for(int k = 0; k < 9; k++){
            if(board[i][k] == temp){
                count++;
            }
        }
        for(int k = 0; k < 9; k++){
            if(board[k][j] == temp){
                count++;
            }
        }
        int sub_i = i/3;
        int sub_j = j/3;
        int c2 = 0;
        for(int m = sub_i*3; m < (sub_i*3)+3; m++){
            for(int n = sub_j*3; n < (sub_j*3)+3; n++){
                if(board[m][n] == temp){
                    c2++;
                }
            }
        }
        if(count == 2 && c2 == 1){
            return true;
        }
        return false;
        
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(helper(board, i, j) == false){
                        return false;
                    }
                }
            }
        }
        return true;        
    }
};