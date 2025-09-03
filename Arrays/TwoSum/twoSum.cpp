class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff; 
        int i = 0; 
        while(i < nums.size()){
            if(diff.find(nums[i]) != diff.end()) return {diff[nums[i]], i};  
            diff[target - nums[i]] = i; 
            i++;
        }
        return {};
    }
};
