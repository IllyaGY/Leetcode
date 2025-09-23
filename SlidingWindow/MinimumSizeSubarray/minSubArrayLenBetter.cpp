class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0; 
        int r = 0; 
        int mn = INT_MAX; 
        int sum = 0; 
        while(r < nums.size()){
            if(sum < target) sum += nums[r]; 
            while(sum >= target && l <= r) {
                mn = min(mn, r - l + 1); 
                sum -= nums[l]; 
                l++; 
            }
            r++; 
        }

        return mn < INT_MAX ? mn : 0; 
    }
};
