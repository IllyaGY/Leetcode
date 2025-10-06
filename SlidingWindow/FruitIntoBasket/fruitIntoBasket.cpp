class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int length = 0; 
        int mx = 0; 
        int i = 0; int j = 0; 
        unordered_map<int,int> mp;
        while(j < fruits.size()){ 
            mp[fruits[j]]++; 
            while(mp.size()>2 && j < fruits.size()){
                mp[fruits[i]]--; 
                if(!mp[fruits[i]]) mp.erase(fruits[i]);
                i++;     
                if(j+1 < fruits.size())
                    mp[fruits[++j]]++; 
            }
            if(mp.size() <=2) mx = max(mx, j - i + 1); 
            j++;
            
        }
        return mx;
    }
};
