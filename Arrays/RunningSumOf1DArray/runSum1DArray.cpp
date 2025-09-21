class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            nums[i] += i ? nums[i-1] : 0; 
        return nums; 
    }
};
