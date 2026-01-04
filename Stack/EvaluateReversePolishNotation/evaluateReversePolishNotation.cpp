class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s; 
        unordered_set<string> m; 
        m.insert("+");
        m.insert("/");
        m.insert("*");
        m.insert("-");
        for(auto &i : tokens){
            if(m.find(i) == m.end()) s.push(stoi(i)); 
            else{ 
                int t = s.top(); 
                s.pop(); 
                char op = i[0];
                switch (op) {
                    case '+': t = s.top() + t; break;
                    case '-': t = s.top() - t; break;
                    case '*': t = s.top() * t; break;
                    case '/': t = s.top() / t; break;
                }
                s.pop();
                s.push(t); 
            }  
        }
        return s.top(); 
    }
};
