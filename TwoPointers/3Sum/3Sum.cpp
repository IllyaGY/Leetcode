class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> res; 
        for(int i = 0; i < nums.size()-2; i++) {
            int j = i + 1; 
            int k = nums.size()-1; 
            while( j < k) {
                if(nums[i] + nums[j] + nums[k] > 0) k--; 
                else if(nums[i] + nums[j] + nums[k] < 0) j++;   
                else {
                    res.push_back({nums[i], nums[j], nums[k]}); 
                    j++; 
                    k--; 
                }
                while(k < nums.size()-1 && k >= 0 && nums[k] == nums[k+1]) k--; 
                while(j > i + 1 && j < nums.size() && nums[j] == nums[j-1]) j++; 
                

            } 
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++; 
            

        }
        return res; 
    }
};
