class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; 
        vector<int> result; 

        int l = 0; 
        int h = 0; 
        
        q.push_back(l); 
        while(h < k){
            while(!q.empty() && nums[q.front()] < nums[h]) q.pop_front();   
            q.push_front(h);          
            h++;
        }
        result.push_back(nums[q.back()]); 

        l++; 
        for(; h < nums.size(); l++, h++){
            while(!q.empty() && q.back() < l) q.pop_back(); 
            while(!q.empty() && nums[q.front()] < nums[h]) q.pop_front(); 
            q.push_front(h); 
            result.push_back(nums[q.back()]); 
        }

        return result; 
    }
};
