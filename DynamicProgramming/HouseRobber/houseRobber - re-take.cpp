class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> v = nums;   
        if(nums.size() == 2) return std::max(nums[0], nums[1]);
        for(int i = 2; i < v.size(); i++){
           v[i] = std::max(v[i-2] + nums[i], std::max(v[i-1], v[i-1]-nums[i-1] + nums[i])); 
        }
        return v[nums.size()-1]; 
    }
};