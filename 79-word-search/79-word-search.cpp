class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int curr_char_index, int i, int j){
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[curr_char_index] != board[i][j]) {
            return false;
        }
        if (curr_char_index == word.length() - 1){
               return true;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool next = helper(board, word, curr_char_index + 1, i+1, j) || 
            helper(board, word, curr_char_index + 1, i, j+1) || 
            helper(board, word, curr_char_index + 1, i-1, j) || 
            helper(board, word, curr_char_index + 1, i, j-1);
        board[i][j] = temp;
        return next;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()){
            return true;
        }
        if (board.empty() || board[0].empty()){
            return false;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if (helper(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};