//
// Created by zy234 on 1/4/19.
//
using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
//my solution: 52ms 45%
class Solution {
public:
    int minMoves(vector<int> &nums) {
        int sum = 0;
        int minElement = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            minElement = min(minElement, nums[i]);
        }
        return sum - minElement * nums.size();
    }
};

int main() {
    vector<int> testArray = {1,2,4};
    Solution test;
    cout<<test.minMoves(testArray)<<endl;
}

