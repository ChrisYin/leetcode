//
// Created by zhenguo on 1/1/19.
//
using namespace std;

#include <stack>
#include <iostream>
#include <cmath>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        stack<int> bitStack;
        bool isNeg = (x<0);
        x = abs(x);
        while(x / 10 != 0){
            int bitTemp = x%10;
            bitStack.push(bitTemp);
            x /= 10;
        }
        bitStack.push(x);
        for(int i = 0; bitStack.size() > 0; i++){
            if(numeric_limits<int>::max() - res < bitStack.top() * pow(10, i)){
                //throw std::runtime_error("overflow\n");
                return 0;
            }
            res += bitStack.top() * pow(10, i);
            bitStack.pop();
        }
        if(isNeg)
            res = -res;
        return res;
    }
};

int main() {
    int testNum = 1534236469;
    Solution test;
    printf("old: %d new: %d\n", testNum, test.reverse(testNum));
}