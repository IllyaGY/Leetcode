class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0; 
        for(auto &i : nums) s+=i; 
        if(s%2) return 0; 
        int diff = s/2; 
        vector<vector<bool>> v(2,vector<bool> (diff+ 1, 0)); 
        v[0][0] = 1; 
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j < v[1].size(); j++){
                v[1][j] = v[0][j];
                int d = j - nums[i]; 
                if(!v[1][j] && d>=0) v[1][j] = v[0][d];  
            }
            if(v[1][diff])return 1; 
            swap(v[1], v[0]); 
        }
        return 0; 
    }
};
