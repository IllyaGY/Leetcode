class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
        int ctr = 0; 
        unordered_map<string, int> m; 
        for(auto &i : strs){
            string temp = i; 
            sort(temp.begin(), temp.end()); 
            if(m.find(temp) == m.end()){ res.push_back({});  m[temp] = ctr; ctr++;}
            res[m[temp]].push_back(i); 
        }
        return res; 
    }
};
