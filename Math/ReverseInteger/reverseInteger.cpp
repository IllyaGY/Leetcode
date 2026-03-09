class Solution {
public:
    int reverse(int x) {
        if(!x) return x; 
        int temp = 0; 
        while(x){
            if(INT_MAX / 10 < abs(temp)) return 0; 
            temp *= 10; 
            temp += x%10; 
            x/=10; 
        }
        return temp; 
    }
};
