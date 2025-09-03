class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<vector<int>> q ;
        vector<int> v; 
        unordered_map<int, int> map;
        for(auto i : nums){
            map[i]++;
        }
        for(auto i : map){
            q.push({i.second, i.first}); 
        }
        while(k){
            v.push_back(q.top()[1]);
            q.pop(); 
            k--;
        }
        return v; 

        //O(n * m log m)
    }
};
