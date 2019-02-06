//
// Created by zy234 on 1/3/19.
//
using namespace std;

#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <iostream>
//my soluton: 20ms 5%
/*class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res(findNums.size(), -1);
        for(int i = 0; i < findNums.size(); i++) {
            auto it = find(nums.begin(), nums.end(), findNums[i]);
            for(int j = it-nums.begin()+1; j < nums.size(); j++) {
                if(nums[j] > nums[it-nums.begin()]){
                    res[i] = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};*/
//O(n) solution: 8ms 75%
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};

int main() {
    vector<int> findNums = {2, 4};
    vector<int> nums = {1, 7, 8, 2, 4, 9};
    Solution test;
    vector<int> res = test.nextGreaterElement(findNums, nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}