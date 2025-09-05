class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> mx; 
        deque<int> mn; 
        int i = 0; 
        int j = 0; 
        int best = 0; ; 
        for(; j < nums.size(); j++){
            while(!mx.empty() && nums[j] > nums[mx.front()]) mx.pop_front(); 
            while(!mn.empty() && nums[j] < nums[mn.front()]) mn.pop_front();
            mx.push_front(j);
            mn.push_front(j);
            while(nums[mx.back()] - nums[mn.back()] > limit){
                i++; 
                if(mx.back() < i) mx.pop_back();
                else if(mn.back() < i) mn.pop_back(); 
                
            }
            best = max(j-i+1, best); 
        }
        return best; 
    }
};
