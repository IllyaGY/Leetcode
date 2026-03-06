class Solution {
public:
    typedef long long ll; 
    int minEatingSpeed(vector<int>& piles, int h) {
        ll mx = 0; 
        ll mn = 1; 
        ll k = INT_MAX;
        for(int & i : piles){ mx = i > mx ? i : mx;} 
        while(mn <= mx){
            ll cap = (mx + mn)/2; 
            ll hr = 0;  
            for(auto &i : piles){
                hr += (i / cap) + (i % cap ? 1 : 0); 
            }
            if(hr > h) mn = cap + 1; 
            else{
                k = cap; 
                mx = cap - 1; 
            }
        }
        return k; 
    }
};
