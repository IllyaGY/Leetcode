class Solution {
public:
    struct op{
        bool operator()(const pair<int, int>& a, const pair<int, int> &b){
            if(a.first == b.first) return a.second > b.second; 
            return a.first > b.first; 
        }  
    };
    int getLeastFrequentDigit(int n) {
        vector<int> v(10, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, op> pq; 
        int mx = 0;
        while(n){
            v[n%10]++; 
            n/=10; 
        }
        for(int i = 0; i < v.size(); i++){
            if(!v[i]) continue; 
            pq.push({v[i], i}); 
        }
        return pq.top().second; 
    }
};