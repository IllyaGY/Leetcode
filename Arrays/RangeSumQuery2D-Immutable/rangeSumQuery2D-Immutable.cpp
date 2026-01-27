class NumMatrix {
public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix; 
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                m[i][j] += (j >= 1 ? m[i][j-1] : 0) + (i >= 1 ? m[i-1][j] : 0) - (i >= 1 && j >= 1 ? m[i-1][j-1] : 0); 
                
            }
            
        } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m[row2][col2] - (col1 >= 1 ? m[row2][col1-1] : 0) - (row1 >= 1 ? m[row1-1][col2] : 0) + (col1 >=1 && row1 >= 1 ? m[row1-1][col1-1] : 0);  
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */