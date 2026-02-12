class Solution {
public:

    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts; 
        vector<int> ends; 
        for(auto &i : intervals){
            starts.push_back(i[0]); 
            ends.push_back(i[1]); 
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end()); 
        int start = 0, end = 0; 
        int ct = 0; 
        int mx = 0; 
        for(; start < starts.size() || end < ends.size(); ){
            if(start < starts.size()) {
                if(starts[start] < ends[end]) {
                    ct++; 
                    start++;
                }
                else if(starts[start] > ends[end]) {
                    ct--; 
                    end++; 
                }
                else{start++; end++;}
            }
            else {ct--; end++;}
            mx = max(mx, ct); 
        }
        return mx; 
    }
};
