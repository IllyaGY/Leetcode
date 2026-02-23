class Solution {
public:
    int countPrimes(int n) {
        int ctr = 0; 
        vector<int> v(n, 1); 
        for(long long i = 2; i < n; i++){
            if(!v[i]) continue; 
            ctr++;
            long long j = i * i;
            while(j < n){
                v[j] = 0; 
                j+=i; 
            }
        }
        return ctr; 
    }
};
