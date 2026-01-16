struct cmp {
    bool operator()(const pair<int,string>& a,
                    const pair<int,string>& b) const {
        if (a.first != b.first)
            return a.first > b.first;   // larger first → worse → goes down
        return a.second < b.second;     // smaller second → worse → goes down
    }
};

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m; 
        for(auto &i : words) m[i]++; 
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq; 
        for(auto &i : m) {
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop(); 
        }
        vector<string> res(k, "");
        int i = pq.size()-1; 
        while(!pq.empty()){
            res[i] = (pq.top().second);
            pq.pop(); 
            i--;  
        }
        return res;
    }
};
