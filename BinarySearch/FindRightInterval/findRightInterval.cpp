class Solution {
public:

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts;
        vector<int> res (intervals.size(), -1); 
        for(int i{0}; i < intervals.size(); i++) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        for(int k = 0; k < intervals.size();k++){
            int val = intervals[k][1];
            int i = 0, j = starts.size()-1; 
            int md = (i + j)/2; 
            while(i < j){
                
                if(starts[md].first >= val) j = md; 
                else if (starts[md].first < val) i = md + 1; 
                
                else break; 

                md = (i + j)/2; 
            }
            if(md < starts.size() && starts[md].first >= val) res[k] = starts[md].second; 

        }
        return res; 
    }
};
