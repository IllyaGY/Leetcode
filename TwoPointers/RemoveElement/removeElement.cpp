class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; int j = nums.size()-1; 
        int s = nums.size(); 
        while(i <= j){
            while(j >= i && nums[j] == val) {
                j--; 
                s--;
            }
            if(j >= i && nums[i] == val) {
                swap(nums[i], nums[j]);
                j--;
                s--;
            }
            i++;
        }
        return s; 
    }
};
