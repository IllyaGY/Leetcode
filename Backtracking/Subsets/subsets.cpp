class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int total = pow( 2, nums.size());
        vector<vector<int>> r; 
        for(int i = 0; i < total; i++){
            vector<int> temp; 
            for(int j = 0; j < nums.size();j++){
                if((i >> j) & 1) temp.push_back(nums[j]);
            }
            r.push_back(temp); 
        }
        return r; 
    }
};
