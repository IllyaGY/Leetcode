class Solution {
public:
    int residuePrefixes(string s) {
        int res = 0; 
        vector<bool> st (256, 0);
        int un = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!st[s[i]]){
                st[s[i]] = 1; 
                un++; 
            }
            if(un == ((i+1)%3)) res++; 
        }
        return res; 
    }
};
