class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0; 
        int current = gas[start]; 
        int temp = start;
        bool bh = 0; 
        do{
            
            while(current < cost[temp]){
                current-=gas[start];
                if(start != temp){
                    current += + cost[start]; 
                } 
                else if(start+1 < gas.size()) current += gas[start+1];
                start++; 
                if(start == gas.size()) return -1; 
                if(!bh && temp < start) temp++;
                if(temp == gas.size()){
                    temp =0;
                    bh=1;
                }
                
            }
            current = current - cost[temp] + gas[temp < gas.size()-1 ? temp + 1 : 0];
            temp++; 
            if(temp == gas.size()){
                temp =0;
                bh=1;
            } 
        }
        while(temp != start); 
        return start; 
    }
};
