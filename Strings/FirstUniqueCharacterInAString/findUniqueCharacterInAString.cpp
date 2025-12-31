class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v (256, 0);
        stack<pair<char, int>> q; 
        for(int i = s.size()-1; i >= 0; i--){ 
            v[s[i]]++;
            if(v[s[i]] == 1) q.push({s[i], i}); 
        }
        while(!q.empty()){
            auto top = q.top(); 
            if(v[top.first] == 1) return top.second;
            q.pop(); 
        }
        return -1; 
    }
};
