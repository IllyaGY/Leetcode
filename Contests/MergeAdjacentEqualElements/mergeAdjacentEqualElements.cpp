class Solution {
public:

    bool helper (vector<long long>& v, vector<int> & nums, int& l){
    if(l >= nums.size()) return 0;
    int i = l;
    l++;
    if(!v.empty() && nums[i] == v.back()) return 1;
    v.push_back(nums[i]);
    
    while(helper(v, nums,l)){
        long long temp = v.back() * 2;
        v.pop_back();
        while(!v.empty() && temp == v.back()) {
            v.pop_back();
            temp *= 2;
        }
        v.push_back(temp);

    }

    return 0;


}
vector<long long> mergeAdjacent(vector<int>& nums) {
    vector<long long> res;
    int l = 0; 
    helper(res, nums, l);
    return res;
}
};
