//
// Created by zhenguo on 1/4/19.
//
using namespace std;

#include <vector>

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2){
            return 0;
        }
        if(n == 2){
            return 1;
        }
        vector<bool> numbers(n, false);
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(!numbers[i]){
                numbers[i] = true;
                cnt++;

            }
        }

        return res;
    }
};
