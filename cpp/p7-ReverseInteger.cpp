//
// Created by zhenguo on 1/1/19.
//
using namespace std;

#include <stack>
#include <iostream>
#include <cmath>
#include <limits>

//my solution: 28ms
/*class Solution {
public:
    int reverse(int x) {
        int res = 0;
        stack<int> bitStack;
        while(x != 0){
            int bitTemp = x%10;
            bitStack.push(bitTemp);
            x /= 10;
        };
        for(int i = 0; bitStack.size() > 0; i++){
            int temp = bitStack.top() * pow(10, i);
            if(temp > 0 && temp > numeric_limits<int>::max()-res){
                //throw runtime_error("overflow\n");
                return 0;
            }
            if(temp < 0 && temp < numeric_limits<int>::min()-res){
                //throw runtime_error("overflow\n");
                return 0;
            }
            res += temp;
            bitStack.pop();
        }
        return res;
    }
};*/

//24ms
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int pop = x % 10;
            x /= 10;
            //judge overflow
            if(res > numeric_limits<int>::max()/10 || (res == numeric_limits<int>::max()/10 && pop > 7))
                return 0;
            if(res < numeric_limits<int>::max()/10 || (res == numeric_limits<int>::min()/10 && pop < -8))
                return 0;
            res = res * 10 + pop;
        }
        return res;
    }
};

int main() {
    int testNum = 1534236469;
    Solution test;
    printf("old: %d new: %d\n", testNum, test.reverse(testNum));
}