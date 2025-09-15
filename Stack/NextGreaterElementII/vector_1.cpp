class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> sol (nums.size(), -1); 
        vector<int> q; 
        int s = nums.size() * 2; 
        for(int i = 0; i < s; i++){
            int dif = i%nums.size(); 
            while(!q.empty() && nums[dif] > nums[q.back()]){
                sol[q.back()] = nums[dif]; 
                q.pop_back(); 
            }
            if(dif == i) q.push_back(dif); // Only insert during the first iteration
        
        }
        return sol; 
    }
};

// 2 1 
