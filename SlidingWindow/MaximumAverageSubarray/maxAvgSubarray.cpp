class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx = INT_MIN; 
        double sum = 0; 
        int j = 0; 
        while(j < k){
            sum+=nums[j];
            j++; 
        }
        mx = sum/k; 
        for(int i = 0; j < nums.size();j++){
            sum+=nums[j]; 
            sum-=nums[i]; 
            i++; 
            mx=max(mx, sum/k); 
            
        }
        return mx; 
    }
};
