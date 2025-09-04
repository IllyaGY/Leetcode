class Solution {
public:
    bool isPalindrome(string s) {
        int val = 0; 
        int i = 0;
        int l = 0; 
        int j = s.size()-1; 
        while(i < j){   
            while(i < j && (s[i] < 'a' || s[i] > 'z') && (s[i] < '0' ||  s[i] > '9') && (s[i] < 'A' || s[i] > 'Z')){
                i++; 
            }
            if(s[i] >= 'A' && s[i] <= 'Z') {
                val^=(s[i] + 32); 
            }
            else val^=s[i];  
            while(i < j && (s[j] < 'a' || s[j] > 'z') && (s[j] < '0' ||  s[j] > '9') && (s[j] < 'A' || s[j] > 'Z')){
                j--; 
            }
            if(s[j] >= 'A' && s[j] <= 'Z') {
                val^=(s[j] + 32); 
            }
            else val^=s[j];

            if(val) return 0; 

            i++; 
            j--; 
        }
        return !val; 
    }
};
