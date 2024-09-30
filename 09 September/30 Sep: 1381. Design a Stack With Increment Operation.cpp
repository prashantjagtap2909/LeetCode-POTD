class CustomStack {
public:
    int n;
    stack<int> stack;
    vector<int> inc;

    CustomStack(int n) {
        this->n = n;
    }

    void push(int x) {
        if (stack.size() < n) {
            stack.push(x);
            inc.push_back(0);
        }
    }

    int pop() {
        if (stack.empty()) return -1;
        if (inc.size() > 1) inc[inc.size() - 2] += inc.back();
        int res = stack.top() + inc.back();
        stack.pop();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val) {
        if (!stack.empty()) {
            int idx = min(k, (int)inc.size()) - 1;
            inc[idx] += val;
        }
    }
};
