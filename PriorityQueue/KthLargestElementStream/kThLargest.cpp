class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> q; 
    int t = 0; 
    KthLargest(int k, vector<int>& nums) {
        this->t = k; 
        sort(nums.begin(), nums.end()); 
        int i = nums.size()-1; 
        while(i >= 0 && k) {
            q.push(nums[i]); 
            i--; 
            k--; 
            if(q.size() > t){
                q.pop(); 
                break; 
            }
        }

    }
    
    int add(int val) {
        q.push(val); 
        if(q.size() > t) q.pop(); 
        return q.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
