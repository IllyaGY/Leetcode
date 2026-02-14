class Solution {
public:
    struct op{
        bool operator()(const pair<long long, int>& a, const pair<long long, int>& b){
            if (a.first == b.first) {
                return a.second > b.second; 
            } 
            return a.first > b.first;
            
        }
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); 
        //roomID
        priority_queue<int, vector<int>, greater<int>> freeRooms;  
        for(int i = 0; i < n; i++) freeRooms.push(i); 
        int mxHeld = n; 
        vector<int> m (n + 1 , 0); 
        m[n] = INT_MIN;
        // roomID, start, end; 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, op> ongoing; 
        for(int i = 0; i < meetings.size(); ){
            long long start = meetings[i][0]; 
            while(!ongoing.empty() && start >= ongoing.top().first) {
                int room = ongoing.top().second; 
                freeRooms.push(room); 
                ongoing.pop(); 
            }
            int room = -1; 
            if(!freeRooms.empty()){
                room = freeRooms.top();
                freeRooms.pop(); 
                if(i < meetings.size()){  
                    ongoing.push({meetings[i][1], room});
                }
                else break; 
            }
            else{
                auto top = ongoing.top();
                room = top.second;
                ongoing.pop(); 
                ongoing.push({top.first + (meetings[i][1] - meetings[i][0]), room});
                

            }
            i++;
            m[room]++; 
            if(m[room] >= m[mxHeld]){
                if(m[room] == m[mxHeld]) mxHeld = min(room, mxHeld); 
                else mxHeld = room; 
            }

            
        }

        return mxHeld;

            
    }
        
    
};
