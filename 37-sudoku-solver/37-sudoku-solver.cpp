class Solution {
public:
    bool isvalid(int row, int col, char c, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == c){
                return false;
            }
            if(board[row][i] == c){
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c){
                return false;
            }
        }
        return true;
    }
    
    
    bool helper(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isvalid(i,j,c, board)){
                            board[i][j] = c;
                            if(helper(board) == true){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true; // when all of the board is filled, no empty cells, no if cond.. i.e 
        // andhuke true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};