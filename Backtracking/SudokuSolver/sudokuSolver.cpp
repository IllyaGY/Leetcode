class Solution {
public:

    void h(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col,vector<vector<int>>&box, bool &found, int r = 1, int c = 1)
    {
        if(board[r-1][c-1] != '.'){
            if(c == 9) {
                if(r < 9) h(board, row, col, box, found, r+1, 1);
                else found = 1;
            } 
            else 
                h(board, row, col, box, found, r, c+1); 

            return; 

        } 
        

        for(int i = 1; i < 10; i++){
            
            if(row[r][i]) continue; 
            if(col[c][i]) continue; 
            if(box[(r-1)/3 * 3 + (c-1)/3][i]) continue; 
            
            board[r-1][c-1] = i + '0'; 
            row[r][i]++;
            col[c][i]++; 
            box[(r-1)/3 * 3 + (c-1)/3][i]++; 

            if(r == 9 && c == 9) {
                found = 1; 
                return; 
            }
            
            if(c == 9) h(board, row, col, box, found, r+1, 1);
            else h(board, row, col, box, found, r, c+1); 

            if(found == 1) return; 

            board[r-1][c-1] = '.'; 
            row[r][i]--;
            col[c][i]--; 
            box[(r-1)/3 * 3 + (c-1)/3][i]--; 

        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool found = 0; 
        vector<vector<int>> row (10, vector<int> (10, 0));
        vector<vector<int>> col (10, vector<int> (10, 0));
        vector<vector<int>> box (10, vector<int> (10, 0));

        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++){
                if(board[i-1][j-1] == '.') continue; 
                row[i][board[i-1][j-1] - '0']++;
                col[j][board[i-1][j-1] - '0']++;
                box[(i-1)/3 * 3 + (j-1)/3][board[i-1][j-1]-'0']++; 
            }
        }
        for(int i = 1; i < 10; i++){
            for(int j = 1; j < 10; j++) {
                h(board, row, col, box, found, i, j);
                if(found) break; 
            }
        }
            
    }
};
