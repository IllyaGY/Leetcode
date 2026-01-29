class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> res; 
        sort(slots1.begin(), slots1.end()); 
        sort(slots2.begin(), slots2.end()); 
        int j = 0;
        for(int i = 0, j = 0; i < slots1.size() && j < slots2.size();){
            int start1 = slots1[i][0];
            int end1 = slots1[i][1]; 
            int start2 = slots2[j][0];
            int end2 = slots2[j][1]; 
            if(end1 < start2) {
                i++; 
                continue; 
            }
            else if(end2 < start1){
                j++; 
                continue; 
            }

            if(min(end1, end2) - max(start1, start2) >= duration) {
                res.push_back(max(start1, start2));
                res.push_back(max(start1, start2) + duration); 
                
                return res; 
            }
            if(i + 1 < slots1.size() && slots1[i+1][0] <= slots2[j][1]){
                i++;
                continue; 
                
                
            }
            else if(j + 1 < slots2.size() && slots2[j+1][0] <= slots1[i][1]){
                j++; 
                continue; 
            
            }
            else i++, j++; 
        }
        return res; 
    }
};
