class Solution {
public:

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(word[0] == board[i][j]) if(rec(board, word, i, j, 0)) return 1; 
            }
        }
        return 0; 
    }

    bool rec (vector<vector<char>>& board, string& word, int i, int j, int idx){
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[idx] != board[i][j]){
            return false; 
        }
        if(idx == word.size() - 1) return 1; 
        char temp = '.'; 
        temp ^= board[i][j]; 
        board[i][j] ^= temp; 
        temp ^= board[i][j];  
        bool val = rec(board, word, i + 1, j, idx + 1) || 
        rec(board, word, i - 1, j, idx + 1) || 
        rec(board, word, i, j + 1, idx + 1) || 
        rec(board, word, i, j - 1, idx + 1);
        board[i][j] = temp; 
        return val; 
    }
};
