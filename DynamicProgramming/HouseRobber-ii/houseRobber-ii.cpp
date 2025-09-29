class Solution {
public:
    int robH(vector<int>& nums, int start, int end) {
        int arr[2] = {0,0}; 
        for(int i = start; i < end; i++){
            int take = arr[1] + nums[i];
            int nt = max(arr[1], arr[0]); 
            arr[0] = take; 
            arr[1] = nt; 
        }
        return max(arr[0], arr[1]);  
    }

    int rob(vector<int>& nums) {
        int arr[2] = {0, 0};  
        if(nums.size() == 1) return nums[0]; 
        return max(robH(nums, 0, nums.size()-1), robH(nums, 1, nums.size())); 
    }
};