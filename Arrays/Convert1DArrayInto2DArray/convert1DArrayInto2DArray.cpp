class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()%m || original.size()/m != n )return {};
        int t = n; 
        vector<vector<int>> r (m, vector<int> (n, 0)); 
        while((--m)>=0){
            while((--t)>=0) 
                r[m][t]=original[m*n + t]; 
            t = n; 
        }
        return r; 
    }
};
