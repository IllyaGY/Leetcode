class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle; 
        int temp = 0; 
        cycle.insert(n); 
        while (n || temp != 1){
            if(!n) {
                if(cycle.find(temp) != cycle.end()) return 0;
                cycle.insert(temp); 
                n = temp; temp = 0;
            } 
            temp+=(n%10)*(n%10); 
            n/=10;
        }
        return temp;
    }
};
