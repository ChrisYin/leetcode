//
// Created by zy234 on 1/4/19.
//
using namespace std;

#include <vector>
#include <iostream>
//dp solution: 12ms 39%(Kadane’s Algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = nums[i] + ((dp[i-1] > 0)?dp[i-1]:0);
            //cout<<"dp"<<i<<": "<<dp[i]<<endl;
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

int main(){
    vector<int> testArray = {-2,-1,-3,-4,-1,-2,-1,-5,-4};
    Solution test;
    int res = test.maxSubArray(testArray);
    cout<<"max subarray: "<<res<<endl;
}