class MyQueue {
    vector<int> s0, s1;
    int front=0;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s0.empty()) front=x;
        s0.push_back(x);
    }
    
    int pop() 
        if (s1.empty()){
            while(!s0.empty()){
                int x=s0.back();
                s0.pop_back();
                s1.push_back(x);
            }
        }
        int x=s1.back();
        s1.pop_back();
        return x;
    }
    
    int peek() {
        if (!s1.empty()){
            s1.back();
        }
        return front;
    }
    
    bool empty() {
        return s0.empty() && s1.empty();
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
