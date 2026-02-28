class Solution {
public:
    int numSteps(string s) {
        int st = 0;
        int carry = 0;
        
        // We stop at index 1 because the most significant bit (index 0) is always '1'
        for (int i = s.size() - 1; i > 0; i--) {
            int sum = (s[i] - '0') + carry;
            
            if (sum == 1) {
                carry = 1;
                st++;   //Since we both go to the next one bit and add a 1 to this one 
            } else {                     
                if(sum != 2) carry = 0; 
                
            }
            st++; 
        }
       
        // After the loop, we are at the very first bit (s[0], which is '1').
        // If we still have a carry of 1, it means that first bit becomes '2' (effectively a '0' with an extra carry).
        // That requires exactly 1 more step (division) to finish.
        return st + carry; 
    }
};
