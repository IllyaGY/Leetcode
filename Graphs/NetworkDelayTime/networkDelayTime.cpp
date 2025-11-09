class Solution {
public:

struct comp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[2] > b[2]; 

    }
};

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> g(n+1);
        for (auto &e: times) g[e[0]].push_back({e[1], e[2]});
        vector<int> dist(n+1, INT_MAX);
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
        auto [du,u]=pq.top(); pq.pop();
        if(du>dist[u]) continue;
            for(auto [v,w]: g[u]){
                if(du + w < dist[v]){
                    dist[v]=du+w;
                    pq.push({dist[v], v});
                }
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){ if(dist[i]==INT_MAX) return -1; mx=max(mx,dist[i]); }

        return mx; 
    }
};
