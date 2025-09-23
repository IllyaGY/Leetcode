class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int t = 0;
        int pref = 0; 
        for(auto &i : nums)
            t+=i;
        for(int i = 0; i < nums.size(); i++){
            if(pref == t - (pref+nums[i])) return i; 
            pref+=nums[i];
        } 
        return -1; 
    } 
};
