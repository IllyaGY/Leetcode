class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c = 0;
        vector<char> v(256,0); 
        for(auto &i : stones) v[i]++; 
        for(auto &i : jewels) c+=v[i];
        return c; 
    }
};