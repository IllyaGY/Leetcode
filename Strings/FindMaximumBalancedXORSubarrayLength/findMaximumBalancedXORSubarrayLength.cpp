class Solution {
public:

    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    int maxBalancedSubarray(vector<int>& nums) {
        unordered_map<pair<int, int>, int, hash_pair> m; 
        int val = 0; 
        int ev = 0; int od = 0; 
        int mx = 0; 
        m[{0, 0}] = -1; 
        for(int i = 0; i < nums.size();i++){
            val^=nums[i]; 
            nums[i]%2 ? od++ : ev++; 
            if(m.find({val, ev - od}) != m.end()){
                mx = std::max(mx, i - m[{val, ev - od}]); 
            }
            else m[{val, ev - od}] = i; 
        }
        return mx; 
    }
};
