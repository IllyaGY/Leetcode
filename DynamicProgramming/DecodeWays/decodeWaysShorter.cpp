class Solution {
public:
    int numDecodings(string s) {
        vector<int> v(s.size()+1, 0); 
        v[0] = 1; 
        v[1] = s[0] != '0' ? 1 : 0;
        for(int i = 2; i < v.size(); i++){
            if(s[i-1] == '0' && s[i-2] == '0') return 0; 
            int val = ((s[i-2]-'0') * 10 + (s[i-1]-'0') < 27) ? v[i-2] : 0; 
            v[i]= (s[i-2] == '0') ?  v[i-1] : (s[i-1] == '0') ? val : v[i-1] + val;
        }
        return v[s.size()]; 
    }
}; 
