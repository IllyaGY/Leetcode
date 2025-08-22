class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> answer(t.size(), 0);
        stack<int> s;
        int size = t.size()-1;
        for(int i = 0; i < t.size(); i++){
            while(!s.empty() && t[s.top()] < t[i]){
                answer[s.top()] = i - s.top();
                s.pop();
            }
            if(i < size && t[i] < t[i+1]){
                answer[i] = 1 ;
            }
            else s.push(i);
        }
        return answer;
    }
};

//Lowest - 9ms Runtime
