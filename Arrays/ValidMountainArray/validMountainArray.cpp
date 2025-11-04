class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 1;
        if(arr.size() < 3) return 0; 
        int c = 0; 
        while(i < arr.size()){
            if(!c && arr[i] > arr[i-1] || c && arr[i] < arr[i-1]) i++; 
            else if(!c && arr[i] < arr[i-1] && i > 1) c=1; 
            else return 0 ;
        }
        return c>0; 
    }
};
