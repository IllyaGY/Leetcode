class Solution {
public:
    int hammingWeight(int n) {
        int i = 0; 
        while(n) {
            i+=n&1;
            n=n>>1; 
        } 
        return i; 
    }
};
