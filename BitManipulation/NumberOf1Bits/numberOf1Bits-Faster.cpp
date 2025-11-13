class Solution {
public:
    int hammingWeight(int n) {
        int i = 0; 
        while(n){
            n&=n-1; 
            i++; 
        }
        return i; 
    }
};
