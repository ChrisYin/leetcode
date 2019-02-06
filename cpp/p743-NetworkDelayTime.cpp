//
// Created by zy234 on 1/31/19.
//
/*
 * How to calculate the delay time??
 *
 * directed edge?
 *
 * graph algorithm: don't know
 *
 * using hashmap to record the delay time of each node
 * then loop to find the max delay time.
 */
using namespace std;

#include <vector>
#include <limits>
#include <set>
#include <iostream>

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        
    }
};

int main(){
    Solution test;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int delayTime = test.networkDelayTime(times, 4, 2);
    cout<<delayTime<<endl;
}