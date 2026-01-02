class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0, j = 0; 
        vector<int> v1 (256, 0); 
        vector<int> v2 (256, 0); 
        vector<int> n (256, 0);
        int s = 0;  
        for(auto &i : s1) v1[i]++; 
        while(j < s2.size()){
            v2[s2[j]]++; 
            if (v2[s2[j]] > v1[s2[j]]) {
                n[s2[j]]++;
                s++; 
            }
            while(s){
                if(n[s2[i]]) {
                    n[s2[i]]--;
                    s--; 
                }
                v2[s2[i]]--;
                i++; 
            }
            if(j - i + 1 == s1.size()) return true; 
            j++;
        }
        return false; 
    }
};
