class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); 
        int i = 0; 
        int t = 0; 
        int j = people.size()-1; 
        while(i < people.size()){ 
            while(j > i && ((people[i] + people[j] > limit) || !people[j] || (j == i))) j--; 
            people[j]=0; 
            people[i]=0;
            t++; 
            while(i < people.size() && !people[i]) i++; 
        } 
        return t; 
    }
};
