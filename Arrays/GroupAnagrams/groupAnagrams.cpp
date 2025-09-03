class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        unordered_map<string, vector<int>> m; 
        vector<string> cp = strs; 
        for(int i = 0; i < strs.size(); i++){
            sort(strs[i].begin(), strs[i].end()); 
            m[strs[i]].push_back(i); 
        }
        for(auto & i : m){
            vector<string> rec;
            for(int j : i.second)
                rec.push_back(cp[j]); 
            res.push_back(rec); 
        }
        return res;
    }
};
