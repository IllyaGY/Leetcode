class Solution {
public:

    static bool greater(const pair<int, float> & v1, const pair<int, double>& v2){
        return v1.first >= v2.first; 
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> pos_left (speed.size(), pair<int, float>()); 
        for(int i = 0; i < speed.size(); i++){
            pos_left[i].first = position[i]; 
            pos_left[i].second = float(target - position[i]) / speed[i]; 
        }
        sort(pos_left.begin(), pos_left.end(), greater); 

        int fleet = 0; 
        float mx = -1; 
        for(int i = 0; i < pos_left.size(); i++){
            if(pos_left[i].second > mx){
                mx = pos_left[i].second; 
                fleet++; 
            }
        }
        return fleet; 
    }
};
