/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int i = 0, j = 10000; 
        while(i <= j){
            int md = (i + j) /2 ; 
            int ro = reader.get(md); 
            if(ro == INT_MAX) {
                j = md - 1;
                continue; 
            }
            else {
                if(ro > target) j = md - 1; 
                else if(ro < target) i = md + 1; 
                else return md; 
            } 
            
        }
        return -1; 
    }
};
