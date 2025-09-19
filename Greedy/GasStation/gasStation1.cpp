class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff; 
        for(int i = 0; i < gas.size(); i++) diff.push_back(gas[i]-cost[i]); 
        int start = 0;  
        int t = 0; 
        int s = 0; 
        while(start < diff.size()){
            while(s + diff[t] < 0) {
                if(start != t) s-=diff[start]; 
                else t++; 
                if(t == diff.size()) t = 0; 
                start++;
                if(start == diff.size()) return -1; 
            } 
             
            if((start && t == start -1) || (!start && t == gas.size()-1)) return start; 
            s+=diff[t++]; 
            if(t == diff.size()) t = 0;  
            

        
        }
        
        return -1; 
    }
};
