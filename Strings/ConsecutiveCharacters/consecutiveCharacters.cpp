class Solution {
public:
    int maxPower(string s) {
        int i = 1; 
        int ctr = 1; 
        for(int j = 1; j < s.size(); j++) i = std::max((ctr = (s[j] == s[j-1] ? ctr+1 : 1)), i);
        return i; 
    }
};