class Solution {
public:
    int missingNumber(vector<int> nums) {
        int k = 0; 
        for(int i = 0; i <= nums.size(); i++) k^=i; 
        for(auto &i : nums) k^=i; 
        return k; 
    }
};
