class Solution {
public:
    struct op{
        bool operator()(string & a, string& b){
            return ((a + b) > (b + a)); 
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> v; 
        for(auto &i : nums) v.push_back(to_string(i)); 
        sort(v.begin(), v.end(), op()); 
        string s = ""; 
        for(auto &i : v){
            s+=i; 
        }
        
        return s[0] == '0' ? "0" : s; 
    }
};
