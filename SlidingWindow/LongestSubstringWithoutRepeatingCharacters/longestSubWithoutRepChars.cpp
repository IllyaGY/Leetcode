class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0; 
        int j = 0; 
        unordered_set<int> set; 
        int mx = 0; 
        while(j < s.size()){
            if(set.find(s[j]) == set.end()) {
                set.insert(s[j]); 
                mx = mx < set.size() ? set.size() : mx; 
            }
            else{
                set.erase(s[i]); 
                i++; 
                j--;
            }
            j++;
            
        }
        return mx; 
    }
};
