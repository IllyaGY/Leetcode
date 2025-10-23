class Solution {
public:
    int numDecodings(string s) {
        vector<unsigned int> v(s.size()+1, 0); 
        v[0] = 1; 
        for(int i = 1; i < v.size(); i++){
            if(s[i-1] == '0' && i >= 2 && s[i-2] == '0') return 0; 
            v[i]= v[i-1] + ((i-2 >= 0 && s[i-2] != '0' && (s[i-2]-'0') * 10 + (s[i-1]-'0') < 27) ? v[i-2] : 0);
            if (i >= 2 && s[i-2] == '0') v[i] = v[i-1]; 
            if(s[i-1] == '0') v[i] = (i>=2 && (s[i-2]-'0') * 10 + (s[i-1]-'0') < 27) ? v[i-2] : 0;    
        }
        return v[s.size()]; 
    }
}; 
