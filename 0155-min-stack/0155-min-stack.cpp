class MinStack {
public:
    double min ;
    stack<double>s;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(s.empty()){
            s.push(val);
            min = val;
            return;
        }
        if(val<min){
            s.push(2*val - min);
            min = val;
            return;
        }
        else{
            s.push(val);
        }

        
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        if(min>s.top()){
            min = 2 * min - s.top();
            s.pop();
            return;
        }
        else{
            s.pop();
            return;
        }
        
    }
    
    int top() {
        if(min>s.top()){
            return min;
        }
        else{
            return s.top();
        }
        
    }
    
    int getMin() {
        if(s.empty()){
            return -1;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */