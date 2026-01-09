class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v = {{}}; 
        for(int i = 0; i < nums.size(); i++){
            vector<int> vec;
            int size = v.size(); 
            for(int j = 0; j < size; j++){
                vec = v[j]; 
                vec.push_back(nums[i]);
                v.push_back(vec); 
            }
                
            
            
            
        }
        return v; 
    }
};

