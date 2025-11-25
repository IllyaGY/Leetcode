class Solution {
public:
    int lengthOfLastWord(string s) {
        int c = 0;
        char last = 0;  
        for(auto &i : s){
            if(i!=' ') {
                c = last == ' ' ? 0 : c; 
                c++;
            }
             
            last = i; 
        }
        return c; 
    }
};
