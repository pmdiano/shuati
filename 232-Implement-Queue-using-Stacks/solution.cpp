class Queue {
    stack<int> stack_in, stack_out;
    void adjust() {
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
    }

public:
    // Push element x to the back of queue.
    void push(int x) {
        stack_in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        adjust();
        stack_out.pop();
    }

    // Get the front element.
    int peek(void) {
        adjust();
        return stack_out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (stack_in.empty() && stack_out.empty());
    }
};