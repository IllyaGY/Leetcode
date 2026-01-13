class Solution {
public:

    void rec(int n, vector<string>& res, int left,  string s = "", int open = 0){
        if(s.size() == n*2 && open == 0){
            res.push_back(s); 
            return; 
        }

        if(open < n && left) rec(n, res, left-1,  s + "(", open+1);

        if(open) rec(n, res, left,  s + ")", open-1); 


        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res; 
        rec(n, res, n);
        return res;
    }
};
