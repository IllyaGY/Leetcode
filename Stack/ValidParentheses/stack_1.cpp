class Solution {
public:
    bool isValid(string s) {
        stack<char> stack; 
        for(char i : s){
            if(i == 40 || i == 91 || i == 123){
                stack.push(i+(i==40 ? 1 : 2));
            }
            else if (!stack.empty() && i == stack.top()) stack.pop(); 
            else return false; 
        }
        return stack.empty();
    }
};