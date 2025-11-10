class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> st (256, 0); 
        int o = s[0]; 
        for(char &i : s) st[i]++;
        for(auto &i : t) {if(!st[i]) return char(i); st[int(i)]--; }
        return '0'; 
    }
};
