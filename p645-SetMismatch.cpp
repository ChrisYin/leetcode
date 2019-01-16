//
// Created by zy234 on 1/15/19.
//
using namespace std;

#include <vector>
#include <iostream>
//my solution: 36ms 90%
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> hashTable(nums.size()+1, 0);
        vector<int> res = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            hashTable[nums[i]]++;
        }
        for(int i = 1; i < hashTable.size(); i++){
            if(hashTable[i] == 2){
                res[0] = i;
            }else if (hashTable[i] == 0){
                res[1] = i;
            }
        }
        return res;

    }
};

int main(){
    vector<int> testArray = {1, 2, 4, 5, 4};
    Solution test;
    vector<int> res = test.findErrorNums(testArray);
    cout<<res[0]<<"  "<<res[1]<<endl;
}
