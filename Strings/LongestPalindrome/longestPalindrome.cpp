class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> even ('z'+1, 0);
        vector<int> odd ('z'+1, 0);
        int odd_sum = 0; 
        int l = 0; 
        for(int i = 0; i < s.size(); i++){ 
            odd[s[i]]++; 
            odd_sum++; 
            if(odd[s[i]] % 2 == 0) {
                even[s[i]] += odd[s[i]];
                l+=odd[s[i]];
                odd_sum -= odd[s[i]];
                odd[s[i]] = 0; 
               
            }
        }
        return l + (odd_sum ? 1 : 0); 

    }
};
