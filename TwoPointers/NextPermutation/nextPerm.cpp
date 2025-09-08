class Solution {
public:
    void nextPermutation(vector<int>& nums) { 
        int i = nums.size()-1; 
        while(i && nums[i-1]>=nums[i]) i--; 
        int j = nums.size()-1; 
        while(j > i && i && nums[j] <= nums[i-1]) j--; 
        swap(nums[i ? i-1 : i], nums[j]); 
        sort(nums.begin()+i, nums.end()); 
    }
};

//2 4 3 -- > 3 2 4
//3 4 2 -- > 4 3 2
