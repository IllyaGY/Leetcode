class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1; 
        int top = 0; 

        while(i < j){ 
            top = (i + j)/2; 
            if(nums[top] >= nums[j]) {
                if(nums[i] > nums[j]) j--; 
                i = top;
            }
            else if (nums[top] < nums[j]) {
                if(nums[top] >= nums[i]) i = top+1; 
                else j = top - 1; 
            } 
        }
        top = i; 
        
        
        if(target >= nums[0] && (top == -1 || target <= nums[top])){
            top = top > -1 ? top : nums.size()-1;
            i = 0;
            while(i <= top){ 
                int m = (i + top)/2; 
                if(nums[m] < target) i = m + 1; 
                else if (nums[m] > target) top = m - 1;
                else return m; 
            }
        }
        else {
            i = top + 1; 
            top = nums.size()-1;
            while(i <= top){ 
                int m = (i + top)/2; 
                if(nums[m] < target) i = m + 1; 
                else if (nums[m] > target) top = m - 1;
                else return m; 
            }
        }
        return -1; 
    }
};
