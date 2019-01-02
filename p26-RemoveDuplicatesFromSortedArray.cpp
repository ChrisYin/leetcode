//
// Created by zy234 on 1/2/19.
//
using namespace std;

#include <vector>
#include <iostream>
//my solution:48ms 11%
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        for(vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++){
            vector<int>::const_iterator itTemp = it + 1;
            //printf("array lenth: %d\n", nums.size());
            while(nums[itTemp - nums.begin()] == nums[it - nums.begin()] && itTemp!=nums.end()){
                nums.erase(itTemp);
            }
        }
        return nums.size();
    }
};*/

//improved: 24ms 64%
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] == nums[i])
                continue;
            i++;
            nums[i] = nums[j];
        }
        return i + 1;
    }
};

int main(){
    vector<int> testArray = {0,0};
    Solution test;
    int length = test.removeDuplicates(testArray);
    for(int i = 0; i < length; i++) {
        printf("%d ", testArray[i]);
    }
}
