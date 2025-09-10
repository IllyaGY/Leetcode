class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& c, int t, int i = 0, int sum = 0){
        static vector<int> v; 

        if(i == c.size() || sum >= t){
            if(sum == t) res.push_back(v); 
            return; 
        }; 
        v.push_back(c[i]); 
        helper(res, c, t, i + 1, sum + c[i]); 
        v.pop_back(); 

        while(i < c.size()-1 && c[i+1] == c[i])
            i++; 
        helper(res, c, t, i + 1, sum); 

    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> res; 
        sort(c.begin(), c.end()); 
        helper(res, c, t); 
        return res; 
    }
};
