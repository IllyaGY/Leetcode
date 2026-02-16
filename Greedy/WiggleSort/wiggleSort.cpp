class Solution {
public:

    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> v; 
        int i = 0; int j=nums.size()-1; 
        while(i <= j){
            v.push_back(nums[i]); 
            if(i!=j) v.push_back(nums[j]); 
            i++;
            j--; 
        }
        swap(v, nums); 
    }
};
