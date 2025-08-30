class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; 
        int j = height.size()-1; 
        int mx = 0; 
        while(i < j){
            int p = min(height[i], height[j]) * (j - i); 
            mx = mx < p ? p : mx; 
            if(height[i] < height[j]){
                i++; 
            }
            else{
                j--; 
            }
        }
        return mx; 
    }
};
