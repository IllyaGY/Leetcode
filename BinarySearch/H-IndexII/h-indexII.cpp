class Solution {
public:
    int hIndex(vector<int>& c) {
        int i = 0, j = c.size()-1;
        int md = (i + j) / 2; 
        int mx = INT_MIN; 
        while(i <= j){
            md = (i + j) / 2; 
            if(c[md] >= c.size() - md) {
                mx = min(int(c.size() - md), c[md]); 
                j = md - 1; 
            }
            else i = md + 1; 
        }
        return mx == INT_MIN ? 0 : mx;
    }
};
