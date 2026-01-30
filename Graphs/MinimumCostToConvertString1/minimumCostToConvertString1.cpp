class Solution {
public:
    int shortest(unordered_map<char, vector<pair<int, char>>>& pairs, char s, char t){
        vector<int> dist (256, -1); 
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq; 
        dist[s] = 0; 
        pq.push({0, s});
        while(!pq.empty()){
            char dest = pq.top().second; 
            int weight = pq.top().first;
            pq.pop();
            if (weight > dist[dest]) continue;
            for(auto &i : pairs[dest]){
                char d = i.second; 
                int w = i.first; 
                if(dist[d] == -1 || dist[d] > dist[dest] + w){
                    dist[d] = dist[dest] + w; 
                    pq.push({dist[d], d});
                }
            }
        }
        return dist[t]; 
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, unordered_map<char, int>> m1; 
        unordered_map<char, vector<pair<int, char>>> pairs; 
        for(int i = 0; i < original.size();i++){
            pairs[original[i]].push_back({cost[i], changed[i]}); 
        }
        long long t = 0; 
        for(int i = 0; i < source.size(); i++){
            if(source[i] != target[i]) {
                int var;
                if((m1.find(source[i]) != m1.end()) && (m1[source[i]].find(target[i]) != m1[source[i]].end())) 
                    var = m1[source[i]][target[i]]; 
                else var = shortest(pairs, source[i], target[i]);
                if(var == -1) return -1; 
                t+=var; 
                m1[source[i]][target[i]] = var; 
            }
        }
        return t; 

    }
};
