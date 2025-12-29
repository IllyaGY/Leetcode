class NumArray {
public:
    vector<int> n; 
    NumArray(vector<int>& nums) {
        n.push_back(nums[0]); 
        for(int i = 1; i < nums.size(); i++) n.push_back(n[i-1] + nums[i]); 
    }
    
    int sumRange(int left, int right) {
        return n[right] - (left ? n[left-1] : 0); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
