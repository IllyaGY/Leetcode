class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> left(position.size(), pair<int,double> ());
        for(int i = 0; i < position.size(); i++){
            left[i].first = position[i];
            left[i].second = (target - position[i]) / double(speed[i]);
        }        
        std::ranges::sort(left, std::ranges::greater());
        int f = 0; 
        double mx = -1; 
        
        for(int i = 0; i < left.size();i++){
            if(left[i].second > mx){
                f++;
                mx = left[i].second;
            }
        }
        

        return f; 
    }
};
