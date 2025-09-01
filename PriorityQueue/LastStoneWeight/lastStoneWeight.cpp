class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q; 
        for(auto i : stones) q.push(i); 
        while(q.size() > 1){
            int stone_1 = q.top(); 
            q.pop();
            int stone_2 = q.top(); 
            q.pop();
            if(stone_1 != stone_2) q.push(stone_1 - stone_2); 
        }
        return q.empty() ? 0 : q.top();
    }
};
