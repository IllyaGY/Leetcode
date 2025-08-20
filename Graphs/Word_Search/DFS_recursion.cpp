bool rec(vector<vector<char>>& board, string& word, int x, int y, int i = 0){
    if(i == word.size()) return true; 
    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[i] != board[x][y]) return false; 
    char bc = 0;
    swap(bc, board[x][y]);
    bool one = rec(board, word, x+1, y, i+1) | rec(board, word, x-1, y, i+1) | rec(board, word, x, y+1, i+1) | rec(board, word, x, y-1, i+1);
    swap(bc, board[x][y]);
    return one; 

}
bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(word[0] == board[i][j]) {
                if(rec(board, word, i, j)) return true; 
            }
        }
    }

    return false; 
}
