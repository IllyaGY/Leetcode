class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = arr.size()-1;
        int c = -1; 
        while(i <= j){
            c = (i+j) / 2; 
            if(arr[c] > x) j = c - 1; 
            else if (arr[c] < x){
                if(c + 1 < arr.size() && arr[c + 1] > x) {c = abs(arr[c] - x) <= abs(arr[c+1] - x) ? c : c + 1; break;}; 
                i = c + 1; 
            } 
            
            else break;
        }
        i = c;
        j = c + 1;
        while(j - i - 1 < k){
            if(j >= arr.size() || i >= 0 && abs(arr[i] - x) <= abs(arr[j] - x)) i--; 
            else j++; 
        }

        return vector<int> (arr.begin() + i + 1, arr.begin() + j); 
    }
};
