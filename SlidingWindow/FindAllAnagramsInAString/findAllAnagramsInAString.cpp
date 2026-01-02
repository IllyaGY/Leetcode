class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i = 0, j = 0; 
        vector<int> a (256, 0); 
        vector<int> m (256, 0); 
        vector<int> r; 
        for(auto &i : p) m[i]++; 
        while(j<s.size()){
            a[s[j]]++; 
            while(i < s.size() && a[s[j]] > m[s[j]]) {
                a[s[i]]--; i++; 
            }
            if(j - i + 1 == p.size()) {
                r.push_back(i);
                a[s[i]]--; 
                i++;
            }
            j++; 
        }
        return r; 
    }
};
