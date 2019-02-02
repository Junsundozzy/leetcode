class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    stack<int> stk;
    stack<int> tmp;
    /** Push element x to the back of queue. */
    void push(int x) {
        
        while (!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        tmp.push(x);
        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = stk.top();
        stk.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */