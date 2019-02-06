//
// Created by zhenguo on 1/4/19.
//
using namespace std;

#include <stack>
#include <iostream>
#include <limits>

//my solution: 28ms 57%
/*class MinStack {
public:
    stack<int> stk;
    stack<int> minstk;

    *//** initialize your data structure here. *//*
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (minstk.empty() || x < minstk.top()) {
            minstk.push(x);
        } else {
            minstk.push(minstk.top());
        }
    }

    void pop() {
        stk.pop();
        minstk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};*/
//improved solution: 28ms 57%
class MinStack {
public:
    stack<int> stk;
    int min = numeric_limits<int>::max();

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(x <= min){
            stk.push(min);
            min = x;
        }
        stk.push(x);
    }

    void pop() {
        if(stk.top() == min){
            stk.pop();
            min = stk.top();
            stk.pop();
        }else{
            stk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout<<minStack.getMin()<<endl;
    minStack.pop();
    minStack.top();
    cout<<minStack.getMin()<<endl;
}
