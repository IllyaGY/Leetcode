class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> queue;
        vector<vector<int>> m (n, vector<int>{}); 
        vector<int> seen(n, 0); 
        if(source == destination) return 1; 
        for(auto i : edges){
            m[i[0]].push_      if(visited[nbr]==0){
                visited[nbr]=1;
                q.push(nbr);
            }
        }back(i[1]); 
            m[i[1]].push_back(i[0]); 
        } 
        if(!m[source].empty()) queue.push(source); 
        while(!queue.empty()){
            int i = queue.front(); 
            seen[i]=1; 
            if(i == destination) return true; 
            queue.pop();
            for(int& k : m[i]){
                if(!seen[k]){
                    queue.push(k);
                    seen[k]=1; 
                }
            }
            
        }
        return false; 
    }
};
