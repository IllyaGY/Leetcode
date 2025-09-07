class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int h = x; 
        long long num = 0; 
        long long prev = num; 
        int prevL = -1; 
        int prevH = -1; 
        if(x <= 1) return x; 
        while(l < h){
            num = (h+l)/2;
            if(num*num < x){
                if(prevH == h && prevL == l) return num; 
                prevL = l;
                prevH = h; 
                l = num; 
                
            }
            else if(num*num > x){
                if(prevH == h && prevL == l) return num - 1; 
                prevH = h; 
                prevL = l; 
                h = num; 
                

            }
            else return num; 
 

        }
        return num;  
    }
};
