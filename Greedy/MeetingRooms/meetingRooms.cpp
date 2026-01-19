class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        for(int i = 0; i < intervals.size(); i++){
            if(i && intervals[i-1][1] > intervals[i][0]) return 0;
        }
        return 1; 
    }
};