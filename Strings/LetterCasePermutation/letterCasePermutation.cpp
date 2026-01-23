class Solution {
public:
    void helper(string& s, vector<string>& r, int i = 0){
        if(i >= s.size()){
            r.push_back(s); 
            return; 
        }; 
        
        if(s[i] < 65) helper(s, r, i+1); 

        else{
            helper(s, r, i + 1); 
            if(s[i] > 90) {
                s[i] -= 32; 
                helper(s, r, i + 1);
                s[i] += 32;  
            }
            else {
                s[i] += 32; 
                helper(s, r, i + 1); 
                s[i] -= 32;
            }
             
        }

    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> r; 
        helper(s, r); 
        return r;
    }
};
