class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int end = nums.size()-1; 
        while(end && nums[end] <= nums[end-1]) end--; 
        int change = end+1; 
        while(change < nums.size() && nums[change] > nums[end ? end - 1 : 0]) change++; 
        swap(nums[change-1], nums[end ? end - 1 : 0]);
        reverse(nums.begin() + end, nums.end()); 
    }
};


// 1 3 5 4
