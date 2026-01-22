class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long, int> m; 
        sort(nums.begin(), nums.end(), greater<int>()); 
        int ctr = 0; 
        for(long i : nums){
            
            int temp = 0;
            m[i]++; 
            if(i == 1) {
                temp = m[i]%2 ? m[1] : m[1] - 1; 
                ctr = max(ctr, temp); 
                continue; 
            }
            
            while(m[i]){
                if(m[i] == 1){
                    break; 
                }
                temp += 2;
                i = pow(i,2);
            }
            if(m[i]){
                temp+=1; 
            }
            else temp -= 1; 
            ctr = max(ctr, temp); 
        }
        return ctr; 
    }
};