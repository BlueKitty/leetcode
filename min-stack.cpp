class MinStack {
    stack<int> num_stack;
    stack<int> min_stack;
public:
    void push(int x) {
        if (min_stack.empty() || min_stack.top() >= x) min_stack.push(x);
        num_stack.push(x);
    }

    void pop() {
        if (num_stack.top() == min_stack.top())
            min_stack.pop();
        num_stack.pop();
    }

    int top() {
        return num_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};