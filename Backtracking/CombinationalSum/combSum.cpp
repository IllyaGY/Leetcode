class Solution {
public:
    void helper(vector<int>& c, int t, vector<vector<int>>& h, int i = 0){
        static int sum = 0; 
        static vector<int> v; 
        if(sum >= t) {
            if(sum == t) h.push_back(v);
            return; 
        }
        if(i == c.size()) return;
        helper(c,t,h,i+1); 
        v.push_back(c[i]); 
        sum+=c[i]; 
        helper(c, t, h, i);
        v.pop_back(); 
        sum-=c[i]; 

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> h; 
        if(candidates.empty()) return h; 
        helper(candidates, target, h);
        return h; 
    }
};
