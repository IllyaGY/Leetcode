class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        queue<int> free; 
        vector<int> num (n, 0); 
        vector<vector<int>> dep (n, vector<int> {}); 
        for(auto i : p){
            dep[i[1]].push_back(i[0]); 
            num[i[0]]++; 
        }
        for(int i = 0; i < num.size(); i++){
            if(!num[i])free.push(i); 
        }
        while(!free.empty()){
            n--; 
            int i = free.front(); 
            free.pop(); 
            for(auto val : dep[i]){
                num[val]--; 
                if(!num[val]) free.push(val); 
            }
        }
        return !n; 
    }
};