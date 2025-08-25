class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;
        vector<int> results (nums.size(), -1); 
        int max = nums.size()*2;
        for(int i = 0; i < max ; i++){
            int ind = i % nums.size(); 
            while(!stack.empty()){
                if(nums[ind] > nums[stack.top()]) {
                    results[stack.top()] = nums[ind];
                    stack.pop();
                } 
                else break; 
            }
            stack.push(ind);

        }       
        
        return results; 
    } 
};