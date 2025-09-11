class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0; 
        int h = arr.size()-1; 
        int prev = -1; 
        int prevMid = -1; 
        int mid = 0; 
        while(l < h) { 
            mid  = (l + h)/2; 
            if((!mid || arr[mid-1] < arr[mid]) && (mid == arr.size()-1 || arr[mid] > arr[mid+1]))
                return mid; 
            else if(mid && arr[mid-1] < arr[mid]){
                l = mid; 
            }
            else if(mid < arr.size()-1 && arr[mid] > arr[mid+1])
                h=mid; 
        }
        return mid; 
    }
};
