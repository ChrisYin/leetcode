//
// Created by zy234 on 1/15/19.
//
using namespace std;

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
//my solution: 24ms 97%
//two times try: read requirement carefully!!!
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>distanceMap;
        unordered_map<int, int>::const_iterator it;
        for(int i = 0; i < nums.size(); i++) {
            it = distanceMap.find(nums[i]);
            if(it != distanceMap.end()){
                if(i - it->second <= k){
                    cout<<i<<" - "<<it->second<<endl;
                    return true;
                }
            }
            distanceMap[nums[i]] = i;

        }
        return false;
    }
};

class BetterSolution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //numSet contains k elements
        unordered_set<int> numSet;
        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++) {
            if(numSet.find(nums[i]) != numSet.end()){
                return true;
            }
            if(i >= k) numSet.erase(nums[i-k]);
            numSet.insert(nums[i]);
        }

        return false;
    }
};

int main(){
    vector<int> testArray = {1, 2, 1};
    int k = 0;
    BetterSolution test;
    cout<<((test.containsNearbyDuplicate(testArray, k))?"true":"false")<<endl;
}