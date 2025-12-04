class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int mx = 0 ;
        for(auto &i : nums) mx = std::max(mx, i); 
        vector<int> v (mx + 1 , 0); 
        for(auto &i : nums) v[i]++;
        int pref = 0; 
        for(int i = 1; i <= mx; i++){
            int temp = v[i]; 
            v[i] = pref;
            pref += temp;
        }
        for(auto &i : nums){
            i = v[i]; 
        }
        return nums;
        
    }
};
