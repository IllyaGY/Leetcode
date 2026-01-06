class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>, vector<pair<int, char>>, greater<pair<int, char>>> pq; 
        priority_queue<pair<int,char>, vector<pair<int, char>>, greater<pair<int, char>>> pq1; 
        vector<int> s (256, 0); 
        for(auto &i : tasks) !s[i]++;
        for(int i = 0; i < 256; i++) if(s[i]) pq.push({-1 * s[i],char(i)});
        int ctr = n+1;
        int c = 0;  
        while(!pq.empty() || !pq1.empty()){
            
            while(!pq1.empty() && ctr - pq1.top().first > n){
                pq.push({-1 * s[pq1.top().second], pq1.top().second});
                pq1.pop(); 
            }
                
            pair<int, char> top=pq.top(); 
            
            if(!pq.empty() && ctr - top.first > n) {
                s[top.second]--;
                pq.pop(); 
                if(s[top.second])
                    pq1.push({ctr, top.second});
                        
            } 
            
            ctr++; 
            c++;
        }
        return c; 
    }
};
