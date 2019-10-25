class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        stack<int> s2;
        int cur;
        int min = s.top();
        while(s.empty()){
            cur = s.top();
            if(cur < min) 
            {
                min = cur;
            } 
            s2.push(cur);
            s.pop();
            
        }
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
