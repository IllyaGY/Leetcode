class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sm ('z'+1, 0);
        int c = 0;
        for(int i = 0; i < s.size(); i++, c++)
            sm[s[i]]++; 

        for(int i = 0; i < t.size(); i++, c--){
            if(!sm[t[i]]) return false; 
            sm[t[i]]--; 
        }
        return !c; 
    }
};
