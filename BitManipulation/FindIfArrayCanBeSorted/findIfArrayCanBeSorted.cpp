class Solution {
public:


    bool canSortArray(vector<int>& b) {
        int prevMax = 0; 

        for(int i = 0; i < b.size();){
            int j = i; 
            int mx = b[i]; 
            int mn = b[i]; 
            while(j < b.size() && __builtin_popcount(b[i]) == __builtin_popcount(b[j])){
                mx = max(mx, b[j]); 
                mn = min(mn, b[j]); 
                j++; 
            } 
            if(prevMax > mn) return 0;
            prevMax = mx; 
            i = j; 
        }


        return 1; 
    }

};