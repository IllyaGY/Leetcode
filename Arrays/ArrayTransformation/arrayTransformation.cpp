class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> a1 = arr; 
        while(1){
            int a = 0; 
            for(int i = 1; i < arr.size()-1; i++) {
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {a1[i]--; a++;}
                else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){ a1[i]++; a++;} 
            }
            arr = a1; 
            if(!a) break; 
        }
        return arr; 
    }
};
