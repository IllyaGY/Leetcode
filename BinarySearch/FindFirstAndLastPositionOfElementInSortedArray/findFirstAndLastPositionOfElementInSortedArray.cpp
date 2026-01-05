class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1; 
        if(nums.empty()) return {-1,-1}; 
        int split = -1; 
        int m = -1; 
        while(i <= j){
            m = (i + j) / 2; 
            if(nums[m] < target) i = m + 1; 
            else if (nums[m] > target) j = m - 1; 
            else {split = m;  break; }
        }
        i = 0, j = nums.size()-1; 
        if(nums[m] != target) return {-1,-1}; 
        vector<int> r {-1, -1}; 

        while(i <= m){
            int md = (i + m) / 2; 
            if(nums[md] < target){
                if(nums[md+1] == target) {r[0] = md + 1; break; }
                else i = md + 1; 
            }
            else if(nums[md] == target) m = md-1; 
        }
        if(m < i && nums[i] == target) r[0] = i;  
        m = split;
        while(m <= j){
            int md = (j + m) / 2; 
            if(nums[md] > target){
                if(nums[md-1] == target) {r[1] = md - 1; break; }
                else j = md - 1; 
            }
            else if(nums[md] == target) m = md+1; 
        }
        if(m > j && nums[j] == target) r[1] = j;  
        return r; 
    }
};
