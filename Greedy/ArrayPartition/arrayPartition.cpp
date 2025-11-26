class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int s = 0; 
        for(int i = 1; i < nums.size(); i+=2){
            s += std::min(nums[i-1], nums[i]); 
        }
        return s; 
    }
};
