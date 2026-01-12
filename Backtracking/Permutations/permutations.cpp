class Solution {
public:
    void helper (vector<int> &nums, vector<int> &curr, vector<vector<int>> &res){
        if(curr.size()==nums.size()){
            res.push_back(curr); 
            return; 
        }

        for(auto & i : nums){
            int b = 1; 
            for(auto & j : curr) if(j == i) {b = 0; break; }
            if(b) {
                curr.push_back(i); 
                helper(nums, curr, res); 
                curr.pop_back(); 
            }
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> r;
        helper(nums, curr, r); 
        return r; 
    }
};
