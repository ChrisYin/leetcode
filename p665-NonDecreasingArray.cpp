//
// Created by zy234 on 1/3/19.
//
using namespace std;

#include <vector>
#include <iostream>
//my solution:36ms 45%
/*class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (i + 1 >= nums.size() || nums[i - 1] <= nums[i + 1]) {
                    nums[i] = nums[i - 1];
                } else if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    return false;
                }
                cnt++;
                if (cnt > 1)
                    return false;
            }
        }
        return true;
    }
};*/

//clear solution: 40ms 32%
class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int positon = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (positon != -1) {
                    return false;
                }
                positon = i;
            }
        }
        return (positon == -1 || positon == 1 || positon == nums.size() - 1 || nums[positon - 2] <= nums[positon] ||
                nums[positon - 1] <= nums[positon + 1]);
    }
};

int main() {
    vector<int> testArray = {3, 4, 2, 3};
    Solution test;
    printf("isNonDecreasingArray: %s\n", test.checkPossibility(testArray) ? "true" : "false");
}