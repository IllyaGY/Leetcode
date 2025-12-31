class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> r; 
        for(int k = 0; k < nums.size()-2; k++){
            if(k && nums[k] == nums[k-1]) continue; 
            int i = k+1, j = nums.size()-1;
            while(i < j){
                int s = nums[i] + nums[j] + nums[k]; 
                if(s < 0) i++; 
                else if(s > 0) j--; 
                else{
                    r.push_back({nums[k], nums[i], nums[j]}); 
                    i++;
                    j--; 
                }
                while(i-1 > k && i < nums.size() && nums[i] == nums[i-1] && j < nums.size() - 1 && j>=0 && nums[j] == nums[j+1]) i++, j--; 
            }
            
        } 
        return r;
    }
};
