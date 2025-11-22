class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false; 
        vector<char> m(256, 0); 
        vector<char> m1(256, 0); 
        for(int i = 0; i < s.size(); i++){
            if((t[i] == m[s[i]] && m1[t[i]] == s[i]) || !m[s[i]] && !m1[t[i]]) {
                m[s[i]] = t[i]; 
                m1[t[i]] = s[i]; 
            }
            else return false; 
        }
        return true; 
    }
};
