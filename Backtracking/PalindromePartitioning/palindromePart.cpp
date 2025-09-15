class Solution {
public:
    void helper(vector<vector<string>> &res, const string& s, int start = 0){
        static vector<string> v = {}; 
        if(start == s.size()) res.push_back(v); 
        int j = start; 
        string st = "";
        while(j < s.size()){ 
            int i = start;
            int k = j;
            
            st+=s[j]; 
            while(i < k){
                if(s[i] == s[k]){
                    i++;
                    k--;
                }
                else break; 
            }     
            if(i>=k){
                v.push_back(st);
                helper(res, s, j+1);
                v.pop_back(); 
            }
            j++; 
        } 
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; 
        if(s.size())helper(res, s);
        return res; 
    }
};

//ALWAYS USE VECTOR STATIC -- FASTER NO COPYING
//ALWAYS PASS STRING BY CONST STRING& REFERENCE FOR DIRECT ACCES --> NO COPYING 

