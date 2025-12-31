class Solution {
public:
    int firstUniqChar(string s) {
        //First - Faster
        vector<int> v(256, INT_MAX); 
        int mn = INT_MAX; 
        for(int i = 0; i < s.size(); i++) {if(v[s[i]] == INT_MAX) v[s[i]]=i; else v[s[i]] = -1;  }
        for(auto i = 0; i < 256; i++) {
            if(v[i] > -1 && v[i] < INT_MAX) mn = min(v[i], mn); 
        }
        return (mn == INT_MAX) ? -1 : mn; 


        //Second-Slower
        unordered_map<int, int> unique; 
        unordered_set<int> seen;
        for(int i = 0; i < s.size(); i++){
            if(unique.find(s[i]) != unique.end()) {seen.insert(s[i]); unique.erase(s[i]);}
            else if(seen.find(s[i]) == seen.end()) unique[s[i]] = i; 
        }
        int mn = INT_MAX; 
        for(auto &i : unique) mn = min(mn, i.second); 
        return mn == INT_MAX ? -1 : mn; 
         
    }
};
