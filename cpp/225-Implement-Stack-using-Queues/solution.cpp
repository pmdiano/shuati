class Stack {
    queue<int> *q_out, *q_helper;
    
public:
    Stack() {
        q_out = new queue<int>();
        q_helper = new queue<int>();
    }

    ~Stack() {
        delete q_out;
        delete q_helper;
    }

    // Push element x onto stack.
    void push(int x) {
        q_helper->push(x);
        while (!q_out->empty()) {
            q_helper->push(q_out->front());
            q_out->pop();
        }
        swap(q_helper, q_out);
    }

    // Removes the element on top of the stack.
    void pop() {
        q_out->pop();
    }

    // Get the top element.
    int top() {
        return q_out->front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q_out->empty();
    }
};
