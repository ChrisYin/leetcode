//
// Created by zhenguo on 1/4/19.
//
using namespace std;

#include <vector>
#include <iostream>
//my solution: 36ms  46%
//three attempts: not include n itself
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        vector<int> numbers(n, -1);
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(numbers[i] == -1){
                numbers[i] = 1;
                cnt++;
                for(int j = 2; j * i < n; j++) {
                    numbers[j*i] = 0;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution test;
    test.countPrimes(3);
}
