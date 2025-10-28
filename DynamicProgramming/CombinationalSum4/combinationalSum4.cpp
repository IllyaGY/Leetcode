class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> v(target+1, 0); 
        v[0] = 1; 
        for(int i = 1; i < v.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i >= nums[j]) v[i] += v[i - nums[j]]; 
            }
        }
        return v[target]; 
    }
};

