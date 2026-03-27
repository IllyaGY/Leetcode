class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mne = INT_MAX, mno = INT_MAX; 
        for(auto &i : nums1) {  
            if(i % 2 == 0) mne = min(mne, i); 
            else mno = min(mno, i); 
        }
        if(mne == INT_MAX && mno == INT_MAX) return 0; 
        else if(mne == INT_MAX || mno == INT_MAX) return 1; 
        if(mne <= mno) return 0; 
        
        return 1; 
    }
};
