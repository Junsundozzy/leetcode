class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    stack<int> stk;
    stack<int> _min;
    void push(int x) {
        stk.push(x);
        if (_min.empty()) {
            _min.push(x);
        }
        else {
            if (x > _min.top()) {
                x = _min.top();
            }
            _min.push(x);
        }
    }
    
    void pop() {
        stk.pop();
        _min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return _min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */