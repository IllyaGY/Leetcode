class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = 0; 
        int max = 1;
        //Might overload better use long long for real cases 
        int sum = 0; 
        int l = 0; 
        while(max <= nums.size()){
            sum+=nums[max-1]; 
            if(sum >= target){
                l = max;
                break;  
            }
            if(max >= nums.size()) return 0; 
            max++; 
        }

        while(min < max){
            while(sum - nums[min] >= target){
                sum-=nums[min++];
                l--; 
            }
            if(max == nums.size()) break; 
            if(max < nums.size()){     
                sum = sum - nums[min] + nums[max]; 
                min++; 
                max++;

            }
        }
        return l; 
    }
};