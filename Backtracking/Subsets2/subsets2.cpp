class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> v = {{}}; 
        int last = 0; 
        for(int i = 0; i < nums.size(); i++){
            int size = v.size(); 
            int j = 0; 
            if(i && nums[i] == nums[i-1]) j = last; 
            last = v.size(); 
            for(; j < size; j++){
                vector<int> vec; 
                vec = v[j]; 
                vec.push_back(nums[i]);
                v.push_back(vec); 
            }      
        }
            
            

        return v; 
    }
};
