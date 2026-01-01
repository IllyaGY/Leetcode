class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        int last_inx = -1, last_max = -1 ;
        vector<vector<int>> r; 
        for(int i = 0; i < intervals.size(); i++){ 
            if(intervals[i][0] <= last_max) last_max = {intervals[i][1] > last_max ? intervals[i][1] : last_max}; 
            else {
                if(last_max != -1){ 
                    r.push_back({intervals[last_inx][0], last_max}); 
                }
                last_max =  intervals[i][1];
                last_inx = i;
            }
        }
        if(last_max > -1) r.push_back({intervals[last_inx][0], last_max});
        return r; 
    }
};
