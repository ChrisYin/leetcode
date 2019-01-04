//
// Created by zy234 on 1/4/19.
//
using namespace std;

#include <iostream>
#include <queue>

//my solution: 4ms 3%
class MyStack {
public:
    queue<int> queueStack;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queueStack.push(x);
        for(int i = 0; i < queueStack.size()-1; i++) {
            queueStack.push(queueStack.front());
            queueStack.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = queueStack.front();
        queueStack.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        return queueStack.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queueStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main(){
    MyStack obj;
    obj.push(2);
    obj.push(3);
    int t0 = obj.pop();
    int t1 = obj.top();
    cout<<t0<<t1<<endl;
}
