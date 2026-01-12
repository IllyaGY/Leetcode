class Solution {
public:
    void helper(vector<vector<char>>& map, vector<string>& res, string& s, string curr, int val = 0){
        if(val >= s.size()){
            res.push_back(curr); 
            return; 
        }
        for(auto &i : map[s[val]-'0']){
            helper(map, res, s, curr + i, val+1); 
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>> map (10, vector<char>()); 
        vector<string> res;
        char last = 'a'; 
        for(int i = 2; i < 10; i++){ 
            int j = 0;
            for(; j < 3 + ((i == 7 || i == 9) ? 1 : 0); j++){
                map[i].push_back(last + j); 
            }
            last+=j; 
        }
        helper(map, res, digits, "");
        return res; 
    }
};
