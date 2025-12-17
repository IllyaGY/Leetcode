class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> n; 
        int t = 0; 
        int i = 0;
        for(; i < nums.size() && nums[i] < 0; i++){}
        t = i; 
        int j = t-1; 
        while(j >= 0 || i < nums.size()){ 
            int val_j = j >= 0 ? abs(nums[j]) : INT_MAX;
            int val_i = i < nums.size() ? nums[i] : INT_MAX; 
            if(val_i < val_j){
                n.push_back(nums[i] * nums[i]);
                i++;
            }
            else {
                n.push_back(nums[j]*nums[j]); 
                j--; 
            }
           
        }
        return n; 
    }
};