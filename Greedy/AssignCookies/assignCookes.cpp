class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content = 0; 
        int j = 0; int i = 0; 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){      
                content++; 
                i++; 
            }
             
            j++; 
            
        }
        return content; 
    }
};
