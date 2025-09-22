class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0; 
        int mx = 0;int s = 0; 
        int st=0;int zero = -1;
        while(i < nums.size()){ 
            if(nums[i] || zero == -1){
                if(!nums[i]){
                    zero = i;  
                }
                s+=1; 
                i++;
            }
            else{
                s -= zero - st + 1; 
                st = zero+1; 
                zero = -1; 
            }
            mx = max(mx, s);
            
        }


        return mx; 
    }
};
