class MyQueue {
private:
    stack<int> stack1, stack2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        while (stack1.size() > 1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int data = stack1.top();
        stack1.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return data;
    }
    
    int peek() {
        while (stack1.size() > 1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int data = stack1.top();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return data;
    }
    
    bool empty() {
        return stack1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
