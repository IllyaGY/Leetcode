class Solution {
public:
    bool helper(string &s, string &p, int si = 0, int pi = 0){
        if(pi >= p.size()) return si >= s.size(); 
        bool match = (si < s.size() && (s[si] == p[pi] || p[pi] == '.'));

        if(pi + 1 < p.size() && p[pi+1] == '*') 
            return 
            helper(s, p, si, pi + 2) || 
            (match && helper(s, p, si+1, pi));

        else 
            return match && helper(s, p, si+1, pi + 1); 
    }

    bool isMatch(string s, string p) {
        return helper(s, p); 
    }
};

