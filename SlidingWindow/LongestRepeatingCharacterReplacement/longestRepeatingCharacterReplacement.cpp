class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0; int j = 0; 
        int mx = 0; 
        int l = 0; 
        unordered_map<int, int> mp; 
        while(j < s.size())   {
            mp[s[j]]++;
            mx = max(mx ,max(mp[s[i]], mp[s[j]]));
            while((j - i + 1) - mx > k){
                if(j - i + 1 > l) {
                    mp[s[j]]--;
                    j--; 
                }
                mp[s[i]]--;
                i++;
                j++;
                mp[s[j]]++;
                mx = max(mx ,max(mp[s[i]], mp[s[j]]));
            }
            l = max(l, j - i + 1); 
            j++; 
        }
        return l; 
    }
};