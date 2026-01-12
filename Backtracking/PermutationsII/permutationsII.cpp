class Solution {
public:
    void helper (vector<int> &nums, vector<int> &curr, vector<vector<int>> &res, vector<int>& count){
        if(curr.size()==nums.size()){
            res.push_back(curr); 
            return; 
        }

        for(int j = 0; j < nums.size(); j++){
            int i = nums[j]; 
            if(j && nums[j] == nums[j-1]) continue; 
            int val = 0;
            if(i > 0) val = i+10; 
            else if(i < 0) val = abs(i);
            if(count[val]){
                curr.push_back(i); 
                count[val]--; 
                helper(nums, curr, res,count); 
                curr.pop_back(); 
                count[val]++; 
            }
    
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> count (22, 0); 
        sort(nums.begin(), nums.end());
        for(auto & i : nums) {
            if(i < 0) count[abs(i)]++; 
            else if (i > 0) count[i+10]++; 
            else count[0]++; 
        }
        vector<int> curr;
        vector<vector<int>> r;
        helper(nums, curr, r, count); 
        return r; 
    }
};
