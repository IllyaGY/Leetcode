class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i<nums.size() && j < nums.size(); i++){
            while(i < nums.size() && nums[i]) i++;
            while(j < nums.size() && (j <= i || !nums[j])) j++;
            if(i < nums.size() && j < nums.size()) swap(nums[i], nums[j]); 
        }
    }
};
