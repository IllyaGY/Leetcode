class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return ""; 
        unordered_map<char, int> m;
        unordered_map<char, int> r; 
        queue<int> ind;
        for(auto k : t) m[k]++;
        for(int i = 0; i < s.size();i++){
            if(m.find(s[i])!=m.end()) ind.push(i); 
        }
        if(ind.empty()) return ""; 
        string mn = "";
        int i = ind.front();
        int j = i; 
        ind.pop(); 
        while(j < s.size()){
            r[s[j]]++; 
            bool b=1;
            for(auto& ptr : m){
                if(r.find(ptr.first) == r.end() || r[ptr.first] < ptr.second) {
                    b = 0; 
                    break;
                }
            }
            if(b){
                if(!mn.size() || mn.size() > j-i+1)
                    mn = s.substr(i, j-i+1);
                break; 
            }
            j++; 
        }
        while(!ind.empty()){
            while(i < ind.front()){
                if(r.find(s[i]) != r.end()){
                    r[s[i]]--;
                    if(!r[s[i]]) r.erase(s[i]); 
                }
                i++; 

                if(j < s.size()-1) {
                    j++; 
                    r[s[j]]++; 
                }
            }
            ind.pop();
            bool b = 1; 
            for(auto& ptr : m){
                if(r.find(ptr.first) == r.end() || r[ptr.first] < ptr.second) {
                    b = 0; 
                    break;
                }
            }
            if(!b) continue; 
            
            //Else
            while(i < j){
                bool o = 0;
                if(m.find(s[i]) == m.end() || r[s[i]] > m[s[i]]){
                    r[s[i]]--; 
                    if(!r[s[i]]) r.erase(s[i]); 
                    i++; 
                    o = 1;
                }
                if(m.find(s[j]) == m.end() || r[s[j]] > m[s[j]]){
                    r[s[j]]--; 
                    if(!r[s[j]]) r.erase(s[j]); 
                    j--; 
                    o = 1; 
                }
                if(!o) break; 
            }
            mn = s.substr(i, j-i+1);
        }
        
        
        return mn;
    }
};
