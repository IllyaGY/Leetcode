class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int s = 0; 
        vector<int> v (256, 0); 
        for(auto &i : magazine) v[i]++, s++; 
        for(auto &i : ransomNote) if(v[i]) v[i]--, s--; else return 0; 
        return 1; 
    }
};

