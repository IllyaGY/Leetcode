class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp; 
        unordered_map<string, char> mp1; 
        vector<string> spl;
        string k = ""; 
        for(int i = 0; i < s.size(); i++){
           if(s[i] != ' ')k+=s[i]; 
           if(s[i] == ' ' && !k.empty() || i == s.size() - 1){
                spl.push_back(k); 
                k = ""; 
           }
           
        }
        if(pattern.size() != spl.size()) return false;  
        for(int i = 0; i < spl.size(); i++){
            if((!mp[pattern[i]].empty() || mp1[spl[i]]) && 
            (mp[pattern[i]] != spl[i] || mp1[spl[i]] != pattern[i])) 
            return false; 
            else {
                mp[pattern[i]] = spl[i]; 
                mp1[spl[i]] = pattern[i]; 
            }
        }
        return true; 
    }
};
