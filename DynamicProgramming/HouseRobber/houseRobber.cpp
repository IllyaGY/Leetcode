class Solution {
public:
    int rob(vector<int>& nums) {
        int arr[2] = {0,0}; 
        int mx = 0; 
        for(int i = 1; i <= nums.size(); i++){
                int temp[2] = {};
                temp[0] = arr[1] + nums[i-1]; 
                temp[1] = max(arr[1], arr[0]);
                swap(arr, temp); 
                mx = max(mx, max(arr[0], arr[1])); 
        }
        return mx; 
    }
};