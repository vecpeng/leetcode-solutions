//用minStack来保存最小值
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> minStack;
    stack<int> resultStack;
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int x) {
        resultStack.push(x);
        minStack.push(min(x, minStack.top()));
    }

    void pop() {
        resultStack.pop();
        minStack.pop();
    }

    int top() {
        return resultStack.top();
    }

    int getMin() {
        return minStack.top();
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

