class Solution {
public:
    int dietPlanPerformance(vector<int>& cal, int k, int lower, int upper) {
        int c = 0; 
        for(int i = 1; i < cal.size(); i++){
            cal[i] = cal[i-1] + cal[i]; 
        }
        int i = k - 1; 
        for(; i < cal.size(); i++){ 
            int temp = cal[i] - (i >= k ? cal[i-k] : 0); 
            if(temp < lower) c-=1; 
            else if(temp > upper) c+=1; 
        }
        return c; 
    }
};
