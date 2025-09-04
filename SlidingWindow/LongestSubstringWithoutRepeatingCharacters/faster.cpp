class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);              // last index of each char
        int i = 0, best = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            unsigned char c = s[j];
            if (last[c] >= i) i = last[c] + 1; 
            last[c] = j;                        
            best = max(best, j - i + 1);        
        }
        return best;
    }
};
