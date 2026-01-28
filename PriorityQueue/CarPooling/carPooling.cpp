class Solution {
public:
    struct op{
        bool operator()(const vector<int>& a, const vector<int>& b){
            if(a[1] == b[1]) {
                if(a[2] == b[2])
                    return a[0] < b[0];
                return a[2] < b[2]; 
            } 
            return a[1] < b[1]; 
        }
    };
    struct op1{
        bool operator()(const vector<int>& a, const vector<int>& b){
            if(a[2] == b[2]) {
                return a[0] < b[0]; 
            } 
            return a[2] > b[2]; 
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), op()); 
        priority_queue<vector<int>, vector<vector<int>>, op1> pq; 
        int cap = 0; 
        for(int i = 0; i < trips.size(); i++){
            while(!pq.empty() && pq.top()[2] <= trips[i][1]) {
                cap-=pq.top()[0];
                pq.pop(); 
            }
          
            cap+=trips[i][0]; 
            pq.push(trips[i]);
            if(cap > capacity) return 0;
            
        }
        return 1; 
    }
};