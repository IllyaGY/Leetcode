class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = s1.size(); 
        unordered_map<char, int> mp;
        for(auto i : s1) mp[i]++; 
        int i = 0;
        int diff = s2.size()-s1.size();  
        do{
            if(mp.find(s2[i]) != mp.end()){
                unordered_map<char,int> temp;
                int l1 = 0; 
                int j = i + s1.size() ; 
                int i1 = i; 
                while(i < j){
                    temp[s2[i]]++;
                    if(mp.find(s2[i])==mp.end()) break;
                    else if (temp[s2[i]] > mp[s2[i]] || mp[s2[i]] - temp[s2[i]] > l - l1) {
                        i = i1;
                        break;  
                    }
                    l1++;  
                    i++; 
                }
                if(l == l1) return true; 
                
            }
            i++;
        }  while(i <= diff);
        return false;
    }
};