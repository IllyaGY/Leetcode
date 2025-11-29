class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res; 
        string temp = "";  
        if(nums.size()) {
            temp = to_string(nums[0]);
            if(nums.size() == 1) res.push_back(temp); 
        }
        int l = 0; 
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i]-1){
                if(l != i-1) res.push_back(temp+"->"+to_string(nums[i-1])); 
                else res.push_back(temp); 
                temp = to_string(nums[i]); 
                l = i; 
            }
            if(i == nums.size() - 1 ) {
                if(l != i) res.push_back(temp+"->"+to_string(nums[i])); 
                else res.push_back(temp); 
            }
        }
        return res; 
    }
};

