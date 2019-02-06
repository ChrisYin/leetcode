using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

class Solution {
public:
    //brute force method
/*    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] == complement){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        throw invalid_argument("invalid nums array\n");
    }*/
    //hash table
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashTable;
        pair<int, int> pairNum;
        for(int i = 0; i < nums.size(); i++) {
            pairNum.first = nums[i];
            pairNum.second = i;
            int complement = target - nums[i];
            if(hashTable.find(complement) != hashTable.end()){
                res.push_back(i);
                res.push_back(hashTable[complement]);
                return res;
            }else{
                hashTable.insert(pairNum);
            }
        }
        throw invalid_argument("invalid nums array\n");
    }

};

int main(){
    vector<int> testArray = {2, 7, 11, 15, 3 , 5, 10};
    int target = 26;

    //print testarray
    for(int i = 0; i < testArray.size(); i++){
        printf("%d ", testArray[i]);
    }
    printf("\n");

    Solution test;
    vector<int> res = test.twoSum(testArray, target);

    printf("[%d %d]: %d + %d = %d\n", res[0], res[1], testArray[res[0]], testArray[res[1]], target);
    return 0;
}
