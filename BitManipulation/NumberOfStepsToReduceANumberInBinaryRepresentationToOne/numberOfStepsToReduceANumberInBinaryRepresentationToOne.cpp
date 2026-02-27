class Solution {
public:
    
    void add(string &s){
        int last = s.size() - 1;
        char carry = '1'; 
        string s1 = ""; 
        while(last >= 0 && (s[last] == '1' || carry == '1')){
           if(s[last] == '1') s[last] = '0';
           else {s[last] = '1'; break;}
           s1+=s[last]; 
           last--;
        }
        if(last < 0 && carry == '1') {
            s1 += '1'; 
            reverse(s1.begin(), s1.end()); 
            swap(s1, s); 
        }
    }
    int numSteps(string s) {
        int st = 0; 
        while(s.size() > 1){
            if(s.back() == '1') add(s);
            else s.pop_back(); 
            st++;  
        }   
        return st;   
    }
};