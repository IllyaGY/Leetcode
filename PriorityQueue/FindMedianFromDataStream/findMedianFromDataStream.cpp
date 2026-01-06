class MedianFinder {
public:
    priority_queue<double, vector<double>, greater<double>> p; //Increasing
    priority_queue<double> q; //Decreasing
    double temp = INT_MIN;  
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q.empty() && p.empty() && temp == INT_MIN) {
            temp = num; 
            return; 
        }
        else if(q.empty() && p.empty()){
            if(temp <= num) {q.push(temp); p.push(num);  }
            else {p.push(temp); q.push(num);  }
            return;
        }
        if(num >= q.top()) p.push(num); 
        else q.push(num); 

        if(int(p.size() - q.size()) > 1){
            q.push(p.top()); 
            p.pop(); 
        } 
        else if(int(q.size() - p.size()) > 1){
            p.push(q.top()); 
            q.pop(); 
        } 

        if(p.top() < q.top()) {
            int t = q.top(); 
            q.pop();
            p.push(t); 
            q.push(p.top()); 
        }
    }
    
    double findMedian() {
        if(q.empty() && p.empty()) return temp; 
        if(p.size() == q.size()) return (p.top() + q.top()) / 2; 
        else return p.size() > q.size() ? p.top() : q.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
