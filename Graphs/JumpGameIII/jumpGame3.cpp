class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q; 
        vector<int> v(arr.size(), 0);
        q.push(start); 
        while(!q.empty()){ 
            start = q.front();
            q.pop(); 
            if(start < 0 || start >= arr.size() || v[start]) continue; 
            if(!arr[start]) return 1; 
            v[start] = 1; 
            q.push(start+arr[start]);
            q.push(start-arr[start]);
        }
        return 0; 
    }
};