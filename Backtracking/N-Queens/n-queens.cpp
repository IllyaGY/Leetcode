class Solution {
public:

    void rec (vector<vector<string>>& res, int n, vector<int>& freeCol, vector<int>& columns, vector<string>& curr, string& s,  int row){
        if(row >= n){
            res.push_back(curr); 
            return; 
        } 
        for(int i = 0; i < n; i++){
            if(!columns[i]) continue; 
            if(abs(freeCol[row - 1] - i) <= 1) continue; 
            int possible = 1; 
            for(int pos = row-2; pos >= 0; pos--){
                if(abs(row - pos) == abs(freeCol[pos] - i)) {
                    possible = 0; 
                    break; 
                }
            }
            if(!possible) continue; 
            s[i] = 'Q'; 
            curr.push_back(s);
            s[i] = '.';  
            freeCol[row] = i;
            columns[i] = 0;
            rec(res, n, freeCol, columns, curr, s, row+1); 
            curr.pop_back(); 
            freeCol[row] = -1;
            columns[i] = 1;

        }


    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> freeCol(n, -1); 
        vector<int> columns(n, 1); 
        vector<string> curr; 
        queue<int> q;
        std::string s(n, '.');
        for(int i = 0; i < n; i++){
            freeCol[0] = i;
            columns[i] = 0;
            s[i] = 'Q'; 
            curr.push_back(s); 
            s[i] = '.';
            rec(res,n, freeCol, columns, curr, s, 1);
            curr.pop_back(); 
            freeCol[0] = -1; 
            columns[i] = 1;

        } 
        return res; 
    }
};
