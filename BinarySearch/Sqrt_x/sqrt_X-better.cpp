class Solution {
public:
    int mySqrt(int x) {
        long i = 0, j = x; 
        while(i <= x){
            long r = (i + j)/2; 
            if(r * r < x && (r+1) *(r+1) < x){
                i = r + 1;  
            }
            else if(r * r > x){  
                j = r - 1;
            }
            else return r; 
        }
        return i;
    }
};
