class Solution {
public:
    int pathSum(vector<int>& nums) {
        int sum = 0; 
        int l = 1; 
        int prev_num = 0; 
        vector<int> mp (49, 0); 
        for(int i = 0; i < nums.size(); i++){
            int level = nums[i]/100; 
            int ind = nums[i]%100/10; 
            int coeff = (level-1) * 10+(ind/2 + ind%2);
            int add = level * 10 + ind; 
            mp[add] =  mp[coeff] + nums[i] % 10;
            sum+=mp[add];
            if(prev_num != coeff) {
                sum-=mp[coeff]; 
                prev_num = coeff; 
                l++;
            }
            
        }
        return sum; 
    }
};
