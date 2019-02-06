//
// Created by zy234 on 1/4/19.
//
using namespace std;

#include <vector>
#include <iostream>
//brute force: 1524ms 2.3%
/*class NumArray {
private:
    vector<int> numArray;
public:
    NumArray(vector<int> nums) {
        numArray = nums;
    }

    int sumRange(int i, int j) {
        int res = 0;
        for(int k = i; k <= j; k++) {
            res += numArray[k];
        }
        return res;
    }
};*/
//simple solution: 184ms 38%
class NumArray {
private:
    vector<int> numSum;
public:
    NumArray(vector<int> nums) {
        if(!nums.empty()) {
            numSum.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++) {
                numSum.push_back(nums[i]+numSum.back());
            }
        }
    }

    int sumRange(int i, int j) {
        return numSum[j] - numSum[i-1];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
int main() {
    vector<int> testArray = {1, 2, 4, 5, 6, 7};
    NumArray obj(testArray);
    cout << obj.sumRange(0, 2) << obj.sumRange(2, 5) << obj.sumRange(0, 5) << endl;
}