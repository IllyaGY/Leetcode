class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end()); 
        vector<vector<int>> v; 

        for(auto &vec : pairs){
            int i = 0; 
            int j = v.size(); 
            while(i < j){
                int m = (j + i)/ 2;
                if(v[m][1] >= vec[0]) j = m; 
                else i = m + 1; 
            }
            if(i >= v.size()) v.push_back(vec); 
            else{
                v[i][1] = std::min(v[i][1], vec[1]); 
            }
        }
        return v.size(); 
    }
};
