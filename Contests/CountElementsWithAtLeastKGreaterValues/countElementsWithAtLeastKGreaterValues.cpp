class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), std::greater<int>()); 
        int ctr = 0; 
        unordered_map<int, vector<int>> m; 
        m[nums[0]] = {0, 0}; 
        ctr+= !k ? 1 : 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                m[nums[i]] = {m[nums[i-1]][0] + m[nums[i-1]][1] + 1, 0};
            }
            else m[nums[i-1]][1]++;
            if(m[nums[i]][0] >= k) ctr++;
        }
        return ctr; 
    }
};
