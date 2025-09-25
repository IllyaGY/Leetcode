class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c = 0; 
        int sum = 0 ;
        unordered_map<int, int> diff; 
        diff[0] = 1; 
        for(auto i: nums){
            sum+=i; 
            int id = (sum%k+k) % k; 
            c += diff[id];
            diff[id]++; 
             
        }
        return c; 
    }
};

// 4 9 9 7 4 1 
// 4 4 4 2 4
