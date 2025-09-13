class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int d = 0; 
        int i = 0; 
        int j = i + 1; 
        while(j < nums.size()){
            while(i >= j) j++;  
            while(j < nums.size() && !nums[j]) j++; 
            while(i < j && nums[i]) i++; 
            if(j < nums.size()) swap(nums[i], nums[j]);
        }
    }
};
